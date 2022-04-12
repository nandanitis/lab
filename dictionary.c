#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Dictionary
{
    int index;
    char *word;
    char *meaning;
    struct Dictionary* next;
    struct Dictionary* prev;   
};
struct Dictionary *head=NULL;
                            //    (head,apple,a fruit)
void insertEnd(struct Dictionary *head,char *w,char *m)
{
    struct Dictionary *new_node=(struct Dictionary *)malloc(sizeof(struct Dictionary));
    struct Dictionary *temp=head;
    
    new_node->word=w;
    new_node->meaning=m;
    if(head==NULL)
    {
        new_node->prev=NULL;
        new_node->next=NULL;
        head=new_node;
        return ;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=NULL;
    new_node->prev=temp;

}

void insertWord(struct Dictionary *head,char *w,char *m)
{
    struct Dictionary *temp=head;
    while(temp->next!=NULL)
    {
        if(w[0]>temp->word[0])
            temp=temp->next;
        if(w[0]==temp->word[0])
        {
            while(i<strlen(w))

        }
    }

}

void delete(struct Dictionary* head,int key)
{
    if(head==NULL)
    {
        printf("No WORD TO BE DELETED\n");
    }
    else if(head->word==key)
    {
        temp=head;
        head=temp->next;
        temp->next->prev=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL)
        {
            
            temp=temp->next;
            if(temp->word==key)
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
            }
        }

    }
}
void find(struct Dictionary* head,int key)
{

    if(head==NULL)
    {
        printf("NO WORD FOUND\n");
    }
    else if(head->word==key)
    {
        printf(" %s\n",head->word);
        printf("%s \n",head->meaning);
    }
    else
    {
        while(temp!=NULL && temp->word!=key)
        {
            temp=temp->next;
            
        }
        if(temp==NULL)
        {
            printf("NO WORD FOUND\n");
        }
        else
        {
            printf("%s",temp->word);
            printf("%s",temp->meaning)
        }
    }
}

void createBaseDictionary()
{
    insertEnd(head,"afforest","establish a forest on previously unforested land");
    insertEnd(head,"aftermath","the consequences of an event, especially a catastrophic one");
    insertEnd(head,"be on cloud nine","feel extreme happiness or elation");
    insertEnd(head,"becalm","make still, steady, or tranquil");
    insertEnd(head,"blithesome","carefree and happy and lighthearted");
    insertEnd(head,"broadsheet","an advertisement intended for wide distribution");
    insertEnd(head,"buffoonish","like a clown");
    insertEnd(head,"caprice","a sudden desire");
    insertEnd(head,"capricious","determined by chance or impulse rather than by necessity");
    insertEnd(head,"causerie","light informal conversation for social occasions");
    insertEnd(head,"congratulatory","expressive of sympathetic pleasure or joy on account of someone's success or good fortune dapper");
    insertEnd(head,"debonaire","having a sophisticated charm");
    insertEnd(head,"devil-may-care","marked by a carefree unconventionality or disreputableness");
    insertEnd(head,"emblazon","decorate with heraldic arms");
    insertEnd(head,"eudaemonia","a contented state of being happy and healthy and prosperous");
    insertEnd(head,"extremum","the point located farthest from the middle of something exultant");
    insertEnd(head,"featherbrained","lacking seriousness");
    insertEnd(head,"felicity","pleasing and appropriate manner or style");
    insertEnd(head,"fiddle-faddle","trivial nonsense");
    insertEnd(head,"gabble","speak (about unimportant matters) rapidly and incessantly");
    insertEnd(head,"gallant","having or displaying great dignity or nobility");
    insertEnd(head,"gilt","having the deep slightly brownish color of gold");
    insertEnd(head,"gleeful","full of high-spirited delight");
    insertEnd(head,"heyday","the period of greatest prosperity or productivity");
    insertEnd(head,"hotheaded","characterized by undue haste and lack of thought or deliberation indefinite quantity an estimated quantity");
    insertEnd(head,"ism","a belief accepted as authoritative by some group or school");
    insertEnd(head,"madcap","characterized by impulsiveness or recklessness");
    insertEnd(head,"majestic","having or displaying great dignity or nobility");
    insertEnd(head,"merry andrew","a person who amuses others by ridiculous behavior");
    insertEnd(head,"natty","marked by up-to-dateness in dress and manners");
    insertEnd(head,"noble-minded","of high moral or intellectual value");
    insertEnd(head,"nuance","a subtle difference in meaning or opinion or attitude");
    insertEnd(head,"phantasy","imagination unrestricted by reality");
    insertEnd(head,"pollyannaish","pleasantly (even unrealistically) optimistic");
    insertEnd(head,"prate","speak about unimportant matters rapidly and incessantly");
    insertEnd(head,"salad days","the best time of youth");
    insertEnd(head,"sappy","overly or insincerely emotional");
    insertEnd(head,"snappy","quick and energetic");
    insertEnd(head,"soda pop","a sweet drink containing carbonated water and flavoring");
    insertEnd(head,"spiffy","marked by up-to-dateness in dress and manners");
    insertEnd(head,"stunner","a very attractive or seductive looking woman");
    insertEnd(head,"timberland","land that is covered with trees and shrubs");
    insertEnd(head,"timbre","the distinctive property of a complex sound");
    insertEnd(head,"tittle-tattle","light informal conversation for social occasions");
    insertEnd(head,"twaddle","pretentious or silly talk or writing");
    insertEnd(head,"vividness","interest and variety and intensity");
    insertEnd(head,"wearisome","so lacking in interest as to cause mental fatigue");
    insertEnd(head,"whimsical","determined by chance or impulse rather than by necessity");
    insertEnd(head,"whimsy","an odd or fanciful or capricious idea");
    insertEnd(head,"zippy","quick and energetic");
}



int main()
{
    createBaseDictionary();
    
    return 0;
}
