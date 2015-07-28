#!/usr/local/bin/perl

use File::Copy qw(copy);

sub mergeFiles {
    my ($src, $dst) = @_;
    
    print "\nMerging $src\ninto    $dst\n";
    
    open(SRC, $src) or die "not able to open $src for reading\n";
    open(DST, ">>", $dst) or die "not able to open $dst for appending\n";
    
    my $line = <SRC>; #Ignore the header
    while ($line = <SRC>) {
        print DST "$line";
    }
    close(SRC);
    close(DST);
    $mergeCount += 1;
}

sub usage {
    print "Usage:\n\n";
    print "uploadMerge.pl /path/to/dir/that/has/new/devices ".
            "/path/to/dir/of/original/upload\n";
}

my $leftDir;
my $rightDir;

if (scalar(@ARGV) < 2) {
    usage();
    exit(1);
} else {
    ($leftDir, $rightDir) = @ARGV;
    print "Got command-line args $leftDir, $rightDir\n";
}

opendir(LDIR, $leftDir) or die "not able to open $leftDir for reading\n";

while (my $file = readdir(LDIR)) {    
    next unless ($file =~ "download|zip");
    $leftFile = File::Spec->catpath("", $leftDir, $file);
    $rightFile = File::Spec->catpath("", $rightDir, $file);
    mergeFiles($leftFile, $rightFile) if ($file =~ 'download$');
    copy($leftFile, $rightFile) if ($file =~ 'zip$');
    $totCount += 1;
}
print "\n\n";
print "Merged $mergeCount download file(s)\n";
print "Copied ", $totCount - $mergeCount, " zip file(s)\n";
print "\n";
print "Compress \"$rightDir\" directory back to zip archive\n";

closedir(LDIR);