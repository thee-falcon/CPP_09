/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:14:36 by omakran           #+#    #+#             */
/*   Updated: 2024/07/30 19:37:12 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }
    std::string str = av[1];
    std::stack<int> stack;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ' || str[i] == '\t') 
            continue;
        if (str[i] >= '0' && str[i] <= '9')
            stack.push(str[i] - '0');
        else if (str[i] == '+')
        {
            if (stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return 1;
            }
            int a = stack.top();
            stack.pop(); // remove the top element
            int b = stack.top();
            stack.pop();
            stack.push(a + b);
            continue;
        }
        else if (str[i] == '-')
        {
            if (stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return 1;
            }
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b - a);
            continue;
        }
        else if (str[i] == '*')
        {
            if (stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return 1;
            }
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a * b);
            continue;
        }
        else if (str[i] == '/')
        {
            if (stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return 1;
            }
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (a == 0)
            {
                std::cout << "Error: Division by zero" << std::endl;
                return 1;
            }
            stack.push(b / a);
            continue;
        }
        if (str[i] < '0' || str[i] > '9'){
            std::cout << "Error" << std::endl;
            return 1;
        }
    }
    if (stack.size() != 1)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    std::cout << stack.top() << std::endl;
    return 0;
}
