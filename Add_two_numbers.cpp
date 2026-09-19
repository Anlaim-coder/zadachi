/*Задача:
Вам даны два непустых связанных списка, представляющих два неотрицательных целых числа. 
Цифры в списках расположены в обратном порядке, и каждый узел содержит одну цифру. 
Сложите два числа и верните сумму в виде связанного списка.
Можно предположить, что в этих двух числах нет ведущих нулей, кроме самого числа 0.

Описание решения:
Для сложения двух чисел используются два связанных списка, в которых 
цифры записаны в обратном порядке. Списки проходятся одновременно, начиная с первых узлов.
на каждом шаге извлекаются текущий числа из списков, если один из списков закончился раньше 
то вместо его цифр берется 0, к цифрам добавляется перенос,полученная сума с помощью остатка 
от деления на 10 преобразуется в одну цифру и если сумма больше девевти то используется перенос, 
далее создается новый узел для нашего нового списка, если после прохождения обоих списков перенос 
равен еденице то создается новый узел в конце списка куда и добавляется этот перенос.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;

        while (l1!=nullptr || l2 != nullptr){
            int num1;
            if(l1 == nullptr){
                num1=0;
            }
            else{
                num1 = l1->val;
            }
            int num2;
            if(l2 == nullptr){
                num2=0;
            }
            else{
                num2 = l2->val;
            }
            
            int num3 = num1+num2+carry;
            if(num3>9){
                num3=num3%10;
                carry=1;
            }
            else{
                carry=0;
            }
            ListNode* result = new ListNode(num3);

            if (head == nullptr){
                head = result;
                tail = result;
            }
            else{
                tail->next = result;
                tail = result;
            }
            if(l1!=nullptr){
                l1=l1->next;
            }
            if(l2!=nullptr){
                l2=l2->next;
            }
        }
        if(carry==1){
            ListNode* last = new ListNode(carry);
            tail->next = last;
        }
        return head;
    }
};
