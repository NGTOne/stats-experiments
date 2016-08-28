#!/bin/perl

use warnings;
use strict;

use File::Find;

my @files;

sub wanted {
	if (/\.csv$/) {
		my $name = $File::Find::name;
		$name =~ s/^\.\/results\/|\.csv$//g;
		push @files, $name;
	}
}

find(\&wanted, "./results");

my @csv;
my @header = ("System", "Mutation", "Crossover", "Problem", "Run");

use Tie::File;

tie my @headerCSV, "Tie::File", "./results/$files[0].csv";
push @header, split(/,/, $headerCSV[0]);
push @csv, \@header;

foreach my $i (0..$#files) {
	print "$files[$i]\n";
	$files[$i] =~ /([^\/]+)\/([^\/]+)\/([^\/]+)\/([^\/]+)\/best-fitnesses-run-(\d+)/;
	my $system = $1;
	my $mutation = $2;
	my $crossover = $3;
	my $problem = $4;
	my $run = $5;
	my @row = ($system, $mutation, $crossover, $problem, $run);

	tie my @resultCSV, "Tie::File", "./results/$files[$i].csv";

	push @row, split(/,/, $resultCSV[1]);
	push @csv, \@row;
}

open (my $csvOutput, '>', "results.csv");

foreach my $i (0..$#csv) {
	print $csvOutput join(",", @{$csv[$i]})."\n";
}
