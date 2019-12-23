#include "file_info.h"
#include "filesort.h"
#include "print_utils.h"

#include <errno.h>
#include <string.h>

/*
**	0) Read flags. 
**	Each argument starting with '-' is consiedered as option string.
**	Return 2 in case of invalid flag.
**	1) Print listing for non-directory arguments if they exist
**	2) Print listing of each directory argument if they exist
**	3) Else print directory listing of "." directory
*/

int	main(int argc, char **argv)
{
	t_flags		flags;
	t_stats		*stats;
	t_file_info	**info;
	int			nfiles;
	t_list		*current;

	if (!(stats = parse_args(&flags, argc, argv)))
		return (2);
	if (!(stats->n_files + stats->n_dirs) && !stats->n_invalid)
		print_dir_listing(flags, ".", 0);
	if (stats->n_files)
	{
		nfiles = stats->n_files;
		info = get_args_fileinfo(stats);
		sort_fileinfo(flags, nfiles, info);
		print_list_files(flags, info, nfiles, 0);
		//clear_fi_array(info, nfiles);
	}
	if (stats->n_dirs)
	{
		current = stats->dirs;
		while (current)
		{
			print_dir_listing(flags, ((t_path_stat *)current->content)->path, 1);
			current = current->next;
		}
	}
	rmstats(stats, &del);
	return (0);
}
