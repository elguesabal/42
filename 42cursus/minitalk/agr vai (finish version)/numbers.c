//       :::::::          :::         ::::::::        ::::::::          :::       ::::::::::        ::::::::    :::::::::::        ::::::::        ::::::::
//     :+:   :+:       :+:+:        :+:    :+:      :+:    :+:        :+:        :+:    :+:       :+:    :+:   :+:     :+:       :+:    :+:      :+:    :+:
//    +:+   +:+         +:+              +:+              +:+       +:+ +:+     +:+              +:+                 +:+        +:+    +:+      +:+    +:+ 
//   +#+   +:+         +#+            +#+             +#++:       +#+  +:+     +#++:++#+        +#++:++#+          +#+          +#++:++#        +#++:++#+  
//  +#+   +#+         +#+          +#+                  +#+     +#+#+#+#+#+          +#+       +#+    +#+        +#+          +#+    +#+             +#+   
// #+#   #+#         #+#         #+#            #+#    #+#           #+#     #+#    #+#       #+#    #+#       #+#           #+#    #+#      #+#    #+#    
// #######        #######      ##########       ########            ###      ########         ########        ###            ########        ########     

#include <unistd.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}


//      :::::::
//    :+:   :+:
//   +:+   +:+ 
//  +#+   +:+  
// +#+   +#+   
//#+#   #+#    
//#######       
static void	print0()
{
	static int	i;

	if(i == 0)
		write(1, "      :::::::\n", 14);
	else if(i == 1)
		write(1, "    :+:   :+:\n", 14);
	else if(i == 2)
		write(1, "   +:+   +:+ \n", 14);
	else if(i == 3)
		write(1, "  +#+   +:+  \n", 14);
	else if(i == 4)
		write(1, " +#+   +#+   \n", 14);
	else if(i == 5)
		write(1, "#+#   #+#    \n", 14);
	else if(i == 6)
		write(1, "#######       \n", 15);
	i++;
}


//        :::
//     :+:+: 
//      +:+  
//     +#+   
//    +#+    
//   #+#     
//#######     
static void	print1(int i)
{
	if(i == 0)
		write(1, "        :::\n", 12);
	else if(i == 1)
		write(1, "     :+:+: \n", 12);
	else if(i == 2)
		write(1, "      +:+  \n", 13);
	else if(i == 3)
		write(1, "     +#+   \n", 12);
	else if(i == 4)
		write(1, "    +#+    \n", 13);
	else if(i == 5)
		write(1, "   #+#     \n", 12);
	else if(i == 6)
		write(1, "#######     \n", 13);
}

static void	prin2()
{
	// static int	i;

	// if(i == 0)
	// 	write(1, "\n",);
	// else if(i == 1)
	// 	write(1, "\n",);
	// else if(i == 2)
	// 	write(1, "\n",);
	// else if(i == 3)
	// 	write(1, "\n",);
	// else if(i == 4)
	// 	write(1, "\n",);
	// else if(i == 5)
	// 	write(1, "\n",);
	// else if(i == 6)
	// 	write(1, "\n",);
	// i++;
}

static void	print3()
{

}

static void	print4()
{

}

static void	print5()
{

}

static void	print6()
{

}

static void	print7()
{

}

static void	print8()
{

}

static void	print9()
{

}

void	print_pid(char *n)
{
	int	i;

	i = 0;
	while(n[i])
	{
		if(n[i] == 0)
		else if(n[i] == 1)
		else if(n[i] == 2)
		else if(n[i] == 3)
		else if(n[i] == 4)
		else if(n[i] == 5)
		else if(n[i] == 6)
		else if(n[i] == 7)
		else if(n[i] == 8)
		else if(n[i] == 9)
		while(i < 7)
		{
			print0(i);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while(argv[1][i])
	{
		print_pid(argv[1]);
		i++;
	}
	return (0);
}