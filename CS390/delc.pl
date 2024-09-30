#!/usr/bin/perl -w

if (@ARGV)
{
    push(@file_list, @ARGV);
}
else
{
    print ("ERROR: no args\n");
    exit 1;
}

foreach $file (@file_list)
{
    print "delete? [y,q] ";
    if (-f $file)
    {
        print "file : " . $file . "\n";
    }
    elsif (-d $file)
    {
        print "dir : " . $file . "\n";
    }
    $input = <STDIN>;
    if ($input =~ ("Y" | "y"))
    {
        push(@delete_list, $file);
    }
    elsif ($input =~ ("Q" | "q"))
    {
        last;
    }
}
print "complete all deletions? [y]: ";
$input = <STDIN>;
if ($input =~ ("Y" | "y"))
{
    foreach $file (@delete_list)
    {
        if (-f $file)
        {
            system("rm " . $file);
        }
        elsif (-d $file)
        {
            system("rm -r " . $file);
        }
    }
}
else
{
    print "nothing has been deleted\n";
}

exit 0;