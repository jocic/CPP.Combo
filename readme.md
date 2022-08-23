# Combo

C++ library used for generating combinations with minimal overhead, designed for use on resource-limited microcontrollers.

## Implementation

```CPP
int set[] = { 1, 2, 3, 4, 5, 6, 7 };
int set_len = sizeof(set) / sizeof(int);

int* combo;
int  combo_len;

int sum;

Combinations c(set, set_len, 4);

combo = c.init(&combo_len);

while (c.has_next()) {

    // Get & Print Next Combination

    c.next(Combinations::BY_VALUE);
    c.print();

    // Do Something With The Values

    sum = 0;

    for (int i = 0; i < combo_len; i++) {
        sum += combo[i];
    }

    cout << "[*] S = " << sum << endl;
}
```

## Output

```
[*] C = { 4, 3, 2, 1 }
[*] S = 10
[*] C = { 5, 3, 2, 1 }
[*] S = 11
[*] C = { 6, 3, 2, 1 }
[*] S = 12
[*] C = { 7, 3, 2, 1 }
...
[*] S = 18
[*] C = { 6, 5, 4, 4 }
[*] S = 19
[*] C = { 7, 6, 5, 4 }
[*] S = 22
[*] C = { 7, 6, 5, 4 }
[*] S = 22
```

## Support

Please don't hesitate to contact me if you have any questions, ideas, or concerns.

My Twitter account is: [@jocic_91](https://www.twitter.com/jocic_91)

My support E-Mail address is: [support@djordjejocic.com](mailto:support@djordjejocic.com)

## Copyright & License

Copyright (C) 2022 Đorđe Jocić

Licensed under the MIT license.
