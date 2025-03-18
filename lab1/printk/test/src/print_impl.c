#include <stddef.h>
#include <stdarg.h>

typedef void (*fmt_callback_t)(void *data, const char *buf, size_t len);

extern void print_char(fmt_callback_t out, void *data, char c, int length, int ladjust);
extern void print_str(fmt_callback_t out, void *data, const char *s, int length, int ladjust);
extern void print_num(fmt_callback_t out, void *data, unsigned long u, int base, int neg_flag, int length,
    int ladjust, char padc, int upcase);

int parse_number(const char *str, int base, const char **next_token) {
    int result = 0;

    while (*str != '\0') {
        char current_digit_char = *str;
        int current_digit = 0;

        if (current_digit_char >= '0' && current_digit_char <= '9') {
            current_digit = current_digit_char - '0';
        } else if (current_digit_char >= 'a' && current_digit_char <= 'z') {
            current_digit = current_digit_char - 'a' + 10;
        } else if (current_digit_char >= 'A' && current_digit_char <= 'Z') {
            current_digit = current_digit_char - 'A' + 10;
        } else {
            break;
        }

        if (current_digit >= base) {
            break;
        }

        result = result * base + current_digit;

        str ++;
    }

    if (next_token != NULL) {
        *next_token = str;
    }

    return result;
}


void vprintfmt(fmt_callback_t out, void *data, const char *fmt, va_list ap) {
	char c;
	const char *s;
	long num;

	int width;
	int long_flag; // output is long (rather than int)
	int neg_flag;  // output is negative
	int ladjust;   // output is left-aligned
	char padc;     // padding char

	for (;;) {
		/* scan for the next '%' */
		/* Exercise 1.4: Your code here. (1/8) */

		/* flush the string found so far */
		/* Exercise 1.4: Your code here. (2/8) */

		/* check "are we hitting the end?" */
		/* Exercise 1.4: Your code here. (3/8) */

		/* we found a '%' */
		/* Exercise 1.4: Your code here. (4/8) */

		/* check format flag */
		/* Exercise 1.4: Your code here. (5/8) */

		/* get width */
		/* Exercise 1.4: Your code here. (6/8) */

		/* check for long */
		/* Exercise 1.4: Your code here. (7/8) */

		neg_flag = 0;
		switch (*fmt) {
		case 'b':
			if (long_flag) {
				num = va_arg(ap, long int);
			} else {
				num = va_arg(ap, int);
			}
			print_num(out, data, num, 2, 0, width, ladjust, padc, 0);
			break;

		case 'd':
		case 'D':
			if (long_flag) {
				num = va_arg(ap, long int);
			} else {
				num = va_arg(ap, int);
			}

			/*
			 * Refer to other parts (case 'b', case 'o', etc.) and func 'print_num' to
			 * complete this part. Think the differences between case 'd' and the
			 * others. (hint: 'neg_flag').
			 */
			/* Exercise 1.4: Your code here. (8/8) */

			break;

		case 'o':
		case 'O':
			if (long_flag) {
				num = va_arg(ap, long int);
			} else {
				num = va_arg(ap, int);
			}
			print_num(out, data, num, 8, 0, width, ladjust, padc, 0);
			break;

		case 'u':
		case 'U':
			if (long_flag) {
				num = va_arg(ap, long int);
			} else {
				num = va_arg(ap, int);
			}
			print_num(out, data, num, 10, 0, width, ladjust, padc, 0);
			break;

		case 'x':
			if (long_flag) {
				num = va_arg(ap, long int);
			} else {
				num = va_arg(ap, int);
			}
			print_num(out, data, num, 16, 0, width, ladjust, padc, 0);
			break;

		case 'X':
			if (long_flag) {
				num = va_arg(ap, long int);
			} else {
				num = va_arg(ap, int);
			}
			print_num(out, data, num, 16, 0, width, ladjust, padc, 1);
			break;

		case 'c':
			c = (char)va_arg(ap, int);
			print_char(out, data, c, width, ladjust);
			break;

		case 's':
			s = (char *)va_arg(ap, char *);
			print_str(out, data, s, width, ladjust);
			break;

		case '\0':
			fmt--;
			break;

		default:
			/* output this char as it is */
			out(data, fmt, 1);
		}
		fmt++;
	}
}
