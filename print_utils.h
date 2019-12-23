#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

void	print_list_files(t_flags flags, t_file_info **fi, int len, int only_name);
void	print_dir_listing(t_flags flags, char *path, int dir_needed);
char	*start_of_name(char *path);
void	pretty_print(t_flags flags, t_file_info **info, int len);

#endif
