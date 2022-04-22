/*#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
static struct poly* head1, * head2;
struct poly
{
    int index;
    float ratio;
    struct poly* next;
};//建立链表，index储存指数，ratio储存系数
void print(struct poly* head)
{
    struct poly* temp;
    temp = head->next;
    if (temp == NULL)
    {
        printf("0\n");
        return;
    }//多项式的输出，若多项式为NULL则直接输出0
    while (temp != NULL)
    {
        if (temp == head->next)
        {
            //printf("%.0f ", temp->ratio);
            if (temp->ratio == 0)
                continue;
            cout << temp->ratio << " ";
            if (temp->index != 0)
            {
                if (temp->index == 1)
                    printf("1\n");
                else
                    printf("%d\n", temp->index);
            }
            else
                printf(" ");
        }//在输出第一项时，系数为正，直接输出，系数为负，也直接输出
        else
        {
            if (temp->ratio > 0)
            {

                //printf("%.0f", temp->ratio);
                cout << temp->ratio << " ";
                if (temp->index != 0)
                {
                    if (temp->index == 1)
                        printf("1\n");
                    else
                        printf("%d\n", temp->index);
                }

                else
                    printf(" ");
            }

            else
            {


                cout << temp->ratio << " ";

                if (temp->index != 0)
                {
                    if (temp->index == 1)
                        printf("1\n");
                    else
                        printf("%d\n", temp->index);
                }

                else
                    printf(" ");
            }//之后的每一项中，系数为正，则加上正号，即加号，系数为负，可直接输出
        }
        temp = temp->next;
    }
    printf("\n");

};
struct poly* creat()
{
    struct poly* temp, * head, * rear, * t;
    int index;
    float ratio;
    int flag = 0;
    head = rear = (poly*)malloc(sizeof(struct poly));
    rear->next = NULL;
    printf("请输入多项式的各项的系数与指数，以空格隔开，输入0 0代表输入结束\n");
    while (1)
    {

        scanf_s("%f %d", &ratio, &index);
        if (ratio == 0 && index == 0)
            return head;
        if (head->next == NULL)
        {
            temp = (poly*)malloc(sizeof(struct poly));
            rear->next = temp;
            rear = temp;
            rear->next = NULL;
            rear->index = index;
            rear->ratio = ratio;
            continue;
        }
        for (t = head->next; t != NULL; t = t->next)
        {
            if (t->index == index)
            {
                flag = 1;
                t->ratio = t->ratio + ratio;
                break;
            }
        }
        if (flag == 0)
        {
            temp = (poly*)malloc(sizeof(struct poly));
            rear->next = temp;
            rear = temp;
            rear->next = NULL;
            rear->index = index;
            rear->ratio = ratio;

        }

    }
    return head;
};//输入数据，在输入时，可能存在输入两次相同系数的数据，此时将两组数据合并
void sort(struct poly* head)
{
    struct poly* temp1, * temp2;
    temp1 = head->next;
    temp2 = NULL;
    while (temp1 != temp2)
    {
        while (temp1->next != temp2)
        {
            if (temp1->index > temp1->next->index)
            {
                temp1->index = temp1->index + temp1->next->index;
                temp1->next->index = temp1->index - temp1->next->index;
                temp1->index = temp1->index - temp1->next->index;
                temp1->ratio = temp1->ratio + temp1->next->ratio;
                temp1->next->ratio = temp1->ratio - temp1->next->ratio;
                temp1->ratio = temp1->ratio - temp1->next->ratio;

            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
        temp1 = head->next;
    }

};//将多项式进行排序，以符合我们通常状态下升幂的次序
//void add(struct poly* head1, struct poly* head2)
//{
//    struct poly* head, * rear, * temp1, * p, * q;
//    head = rear = (poly*)malloc(sizeof(struct poly));
//    rear->next = NULL;
//    p = head1->next;
//    q = head2->next;
//    while (p != NULL || q != NULL)
//    {
//
//
//        if (p == NULL || q == NULL)
//        {
//            if (p == NULL)
//            {
//                while (q != NULL)
//                {
//                    temp1 = (poly*)malloc(sizeof(struct poly));
//                    rear->next = temp1;
//                    temp1->next = NULL;
//                    temp1->index = q->index;
//                    temp1->ratio = q->ratio;
//                    rear = temp1;
//                    q = q->next;
//                }
//            }//求和时，若head1为空，则直接将head2复制到新结果中去
//            else if (q == NULL)
//            {
//                while (p != NULL)
//                {
//                    temp1 = (poly*)malloc(sizeof(struct poly));
//                    rear->next = temp1;
//                    temp1->next = NULL;
//                    temp1->index = p->index;
//                    temp1->ratio = p->ratio;
//                    rear = temp1;
//                    p = p->next;
//                }
//            }//若head2为空，则将head1复制到结果中去
//        }
//        else
//        {
//            if (p->index < q->index)
//            {
//                temp1 = (poly*)malloc(sizeof(struct poly));
//                temp1->index = p->index;
//                temp1->ratio = p->ratio;
//                rear->next = temp1;
//                rear = temp1;
//                rear->next = NULL;
//                p = p->next;
//            }
//            else if (p->index > q->index)
//            {
//                temp1 = (poly*)malloc(sizeof(struct poly));
//                temp1->index = q->index;
//                temp1->ratio = q->ratio;
//                rear->next = temp1;
//                rear = temp1;
//                rear->next = NULL;
//                q = q->next;
//            }
//            else
//            {
//                temp1 = (poly*)malloc(sizeof(struct poly));
//                temp1->index = p->index;
//                temp1->ratio = q->ratio + p->ratio;
//                if (temp1->ratio != 0)
//                {
//                    rear->next = temp1;
//                    rear = temp1;
//                    rear->next = NULL;
//                    p = p->next;
//                    q = q->next;
//                }
//                else
//                {
//                    p = p->next;
//                    q = q->next;
//                }
//            }
//
//        }//若head1和head2都不为空，则按照升幂的次序将其排序相加，系数为0的项不需要，注意，一定要按照次序来，少使用排序函数
//    }
//    print(head);
//    
//};//对两多项式进行求和，求和结果储存在另一个结构体中
void sub(struct poly* head1, struct poly* head2)
{
    struct poly* head, * rear, * temp1, * temp2, * p, * q;
    head = rear = (poly*)malloc(sizeof(struct poly));
    head->next = rear->next = NULL;
    p = head1->next;
    q = head2->next;

    while (p != NULL || q != NULL)
    {
        if (p == NULL || q == NULL)
        {
            if (p == NULL)
            {
                while (q != NULL)
                {
                    temp1 = (poly*)malloc(sizeof(struct poly));
                    rear->next = temp1;
                    temp1->next = NULL;
                    temp1->index = q->index;
                    temp1->ratio = -q->ratio;
                    rear = temp1;
                    q = q->next;
                }
            }
            else if (q == NULL)
            {
                while (p != NULL)
                {
                    temp1 = (poly*)malloc(sizeof(struct poly));
                    rear->next = temp1;
                    temp1->next = NULL;
                    temp1->index = p->index;
                    temp1->ratio = p->ratio;
                    rear = temp1;
                    p = p->next;
                }
            }
        }
        else
        {
            if (p->index < q->index)
            {
                temp1 = (poly*)malloc(sizeof(struct poly));
                temp1->index = p->index;
                temp1->ratio = p->ratio;
                rear->next = temp1;
                rear = temp1;
                rear->next = NULL;
                p = p->next;
            }
            else if (p->index > q->index)
            {
                temp1 = (poly*)malloc(sizeof(struct poly));
                temp1->index = q->index;
                temp1->ratio = -q->ratio;
                rear->next = temp1;
                rear = temp1;
                rear->next = NULL;
                q = q->next;
            }
            else
            {
                temp1 = (poly*)malloc(sizeof(struct poly));
                temp1->index = p->index;
                temp1->ratio = p->ratio - q->ratio;
                if (temp1->ratio != 0)
                {
                    rear->next = temp1;
                    rear = temp1;
                    rear->next = NULL;
                    p = p->next;
                    q = q->next;
                }
                else
                {
                    p = p->next;
                    q = q->next;
                }
            }

        }
    }
    print(head);
};//多项式求差，与求和同理


int main()
{
    head1 = creat();
    head2 = creat();
    sort(head1);
    sort(head2);
    /*printf("\n多项式a(x)为：\n");
    print(head1);
    printf("\n多项式b(x)为：\n");
    print(head2);
    printf("\n两多项式之和为：\n");
    add(head1, head2);
    printf("\n两多项式之差为：\n");
    sub(head1, head2);
    struct poly* temp;
    temp = head1;
    while (temp != NULL)
    {
        free(temp);
        temp = temp->next;
    }
    temp = head2;
    while (temp != NULL)
    {
        free(temp);
        temp = temp->next;
    }
    //释放空间
    return 0;
}
*/
#include<stdio.h>
const int maxx = 1e3;

struct Node {
	int x;
	int m;
	int isok;//代表已经相加？ 
};
Node a[maxx];
Node b[maxx];
int cnt1, cnt2;
void subtract(Node a[], Node b[], int cnt1, int cnt2) {

	for (int j = 0;j < cnt2;j++) {
		b[j].x = -b[j].x;
	}

	int index = 0;
	for (int i = 0;i < cnt1;i++) {
		for (int j = 0;j < cnt2;j++) {
			if (a[i].m == b[j].m) {
				b[j].isok = 1;
				a[i].x = a[i].x + b[j].x;
				break;
			}
		}
	}
	
	printf("\n相减后的结果：");
	for (int i = 0;i < cnt1;i++) {
		if (a[i].x < 0) printf(" ");
		printf("%d*x^%d", a[i].x, a[i].m);
		if (a[i + 1].x > 0) printf(" + ");
	}
	for (int j = 0;j < cnt2;j++) {
		if (b[j].isok == 0) {
			if (b[j].x < 0) printf(" ");
			printf("%d*x^%d", b[j].x, b[j].m);
			if (b[j + 1].x > 0) printf(" + ");
		}
	}
}

int main() {
	
	scanf("%d", &cnt1);
	printf("3 1\n");
	for (int i = 0;i < cnt1;i++) {
		scanf("%d%d", &a[i].x, &a[i].m);
	}

	scanf("%d", &cnt2);
	printf("-3 2\n");
	for (int i = 0;i < cnt2;i++) {
		scanf("%d%d", &b[i].x, &b[i].m);
	}

	int n;
	printf("8.3 3\n");
	printf("#");
	while (scanf("%d", &n)) {
		subtract(a, b, cnt1, cnt2);
				
	}
	return 0;
}