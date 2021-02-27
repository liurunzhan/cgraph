use strict;
use warnings;
use Module::Build;

my $builder = Module::Build->new (
	module_name => "cgraph",
	license     => "GPL-3.0",
	dist_author => "liurunzhan",
	configure_requires => {
		"Module::Build" => "0",
	}
);

$builder->create_build_script();