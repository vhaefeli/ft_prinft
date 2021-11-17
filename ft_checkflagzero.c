static bool ft_checkflagzero(const char *input, int j, const int nbflag)
{
    bool flagzero;

    if (ft_checktype(input, ".", j, nbflag))
            return (false);
    if (ft_checktype(input, "0", j. nbflag))
    {
        while (k < nbflag)
        {
            if (input[k] < 48 && input[k+1] == 0)
                return (true);
            k++;
        }
    }
    return (false);
}
