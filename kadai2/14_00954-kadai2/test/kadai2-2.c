int printf ();

int mrn (int n)
{
    if (0 < n && n < 10)
        return 120/n;
    else
        return n;
}

int main ()
{
  int i;

  i = 0;
  while (i < 15) {
    printf ("mrn(%d) = %d\n", i, mrn(i));
    i = i+2;
  }
}
