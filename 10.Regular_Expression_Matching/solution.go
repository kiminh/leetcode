package main

type item_type_t int

const schar item_type_t = 1   // a
const chardup item_type_t = 2 //a*
const anydup item_type_t = 3  //.*
const dot item_type_t = 4     //.

type item_t struct {
	Type item_type_t
	Char byte
}

func parse_pattern(p string) []item_t {
	result := []item_t{}
	for i := 0; i < len(p); {
		if p[i] == '.' {
			if i < len(p)-1 && p[i+1] == '*' {
				result = append(result, item_t{anydup, ' '})
				i += 2
			} else {
				result = append(result, item_t{dot, ' '})
				i += 1
			}
		} else if p[i] != '*' {
			if i < len(p)-1 && p[i+1] == '*' {
				result = append(result, item_t{chardup, p[i]})
				i += 2
			} else {
				result = append(result, item_t{schar, p[i]})
				i += 1
			}
		}
	}
	return result
}

type absorb_type int

const not_absorb absorb_type = 0
const absorb_single_char absorb_type = 1
const absorb_single_any absorb_type = 2
const absort_infinit absorb_type = 3

func can_be_absorb(pat item_t, char byte) absorb_type {
	switch pat.Type {
	case schar:
		if pat.Char == char {
			return absorb_single_char
		}
	case chardup:
		if pat.Char == char {
			return absort_infinit
		}
	case anydup:
		return absort_infinit
	case dot:
		return absorb_single_any
	}
	return not_absorb
}

func isMatch(s string, p string) bool {
	pattern := parse_pattern(p)
	result := make([][]absorb_type, len(pattern))
	for i, _ := range result {
		result[i] = make([]absorb_type, len(s))
	}
	for pat := 0; pat < len(result); pat++ {
		for ch := 0; ch < len(result[pat]); ch++ {
			if ch == 0 || result[pat][ch-1] > 0 {
				can := can_be_absorb(pattern[pat], s[ch])
				if can == 
				result[pat][ch] = can_be_absorb(pattern[pat], s[ch])
				if result[pat][ch] > 0 {
					continue
				}
			}
			if pat == 0 || result[pat-1][ch] > 0 {
				if pattern[pat].Type == chardup || pattern[pat].Type == anydup {
					result[pat][ch] = absort_infinit
				}
			}
			if (ch == 0 && pat == 0) || result[pat-1][ch-1] > 0 {
				result[pat][ch] = can_be_absorb(pattern[pat], s[ch])
				if result[pat][ch] > 0 {
					continue
				}
			}
		}
	}
	return result[len(pattern)-1][len(s)-1] > 0
}
