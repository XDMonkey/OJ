bool isMatch(const char *s, const char *p) {
  const char *star = NULL;
  const char *backup = NULL;
        
  while (*s) {
    if (*p == '*') {
      backup = s;
      star = ++p;
    }
    else if (*p == '?' || *p == *s) {
      s++;
      p++;
    }
    else if (star) {
      p = star;
      s = ++backup;
    }
    else
      break;
  }
        
  while (*p == '*')
    p++;
  return !*s && !*p;
}