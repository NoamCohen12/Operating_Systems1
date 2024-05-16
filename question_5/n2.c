int best = 0;
for (int a = 0; a < n; a++)
{
    int sum = 0;
    for (int b = a; b < n; b++)
    {
        sum += array[b];
        best = max(best, sum);
    }
}
cout << best << "\n";
