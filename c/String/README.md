# A custom library to simulate string operation func in golang

- [x] func EqualFold(s, t string) bool
- [x] func Index(s, substr string) int
- [ ] func IndexAny(s []byte, chars string) int
- [x] func IndexByte(b []byte, c byte) int
- [ ] func IndexFunc(s string, f func(rune) bool) int
- [ ] func IndexRune(s string, r rune) int
- [ ] func LastIndex(s, substr string) int
- [ ] func LastIndexAny(s, chars string) int
- [ ] func LastIndexByte(s string, c byte) int
- [ ] func LastIndexFunc(s string, f func(rune) bool) int

- [ ] func TrimSpace(str string) string
- [ ] func HasPrefix(s string, prefix string) bool
- [ ] func HasSuffix(s string, suffix string) bool
- [ ] func Replace(str string, old string, new string, n int)
- [ ] func Title(s string) string
- [ ] func ToTitle(s string) string
- [x] func ToLower(str string) string
- [x] func ToUpper(str string) string
- [ ] func Contains(s, substr string) bool
- [ ] func ContainsAny(s,chars string)bool
- [x] func Count(s, sep string) int
- [ ] func Repeat(str string, count int)string
- [ ] func Trim(str string, cut string)
- [ ] func TrimLeft(str string, cut string)
- [ ] func TrimRight(str string, cut string)
- [ ] func TrimPrefix(S string, prefix string) string
- [ ] func TrimSpace(s string) string
- [ ] func Fields(str string) []string
- [ ] func FieldsFunc(s []byte, f func(rune) bool) [][]byte
- [ ] func ContainsRune(s string, r rune) bool
- [ ] func Split(str string, split string) []string
- [ ] func Join(s1 []string, sep string) string
- [ ] func SplitN(s, sep string, n int) []string
- [ ] func SplitAfter(S String, sep string) []string
- [ ] func SplitAfterN(string s, sep string, n int) []string
- [ ] func Cut(s, sep string) (before, after string, found bool)