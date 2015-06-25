#!/usr/local/bin/perl

use File::Copy qw(copy);

sub mergeFiles {
    my ($src, $dst) = @_;
    
    print "Gonna merge $src into $dst\n";
    
    open(SRC, $src) or die "not able to open $src for reading\n";
    open(DST, ">>", $dst) or die "not able to open $dst for appending\n";
    
    my $line = <SRC>; #Ignore the header
    while ($line = <SRC>) {
        print DST "$line";
    }
    close(SRC);
    close(DST);
}

my $leftDir;
my $rightDir;

if (scalar(@ARGV) < 2) {
    die "need left and right directory names to merge\n";
} else {
    ($leftDir, $rightDir) = @ARGV;
    print "Got cmd line args $leftDir, $rightDir\n";
}

opendir(LDIR, $leftDir) or die "not able to open $leftDir for reading\n";

while (my $file = readdir(LDIR)) {    
    next unless ($file =~ "download|zip");
    $leftFile = File::Spec->catpath("", $leftDir, $file);
    $rightFile = File::Spec->catpath("", $rightDir, $file);
    mergeFiles($leftFile, $rightFile) if ($file =~ "download");
    copy ($rightFile, $rightFile) if ($file =~ 'zip$');
}

closedir(LDIR);