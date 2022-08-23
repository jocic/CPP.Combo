# Combo

Lorem ipsum bla bla...

## Implementation

```C
int set[] = { 1, 2, 3, 4 };
int set_len = sizeof(set) / sizeof(int);

int* combo;
int  combo_len;

Combinations c(set, set_len, "1-3");

combo = c->init(&combo_len);

while (c.has_next()) {
    c.next(Combinations::BY_VALUE);
    c.print();
}
```