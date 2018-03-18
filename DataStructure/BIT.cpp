//��������poj2299
/*
 *���� http://codeforces.com/contest/777/submission/25005987
 *�����滻��������ֵ
 */

//�����޸ģ� �����ѯ(��������������ͻ����������ֵ�Ȳ���)
struct BIT{
    int n;
    ll c[N];
    void init(int _n){
        n=_n;
        for(int i=1;i<=n;i++)c[i] = 0;
    }
    void update(int p, ll x){  //������� ��Ҷ�ӻ��Ǹ����¿����
        for(int i=p; i<=n; i+=i&-i)c[i] += x;
    }
    ll query(int p){ //�����ѯ
        ll ret = 0;
        for(int i=p; i>0; i-=i&-i)ret += c[i];
        return ret;
    }
}bit;

//�����޸ģ� �����ѯ
һ��ʼ�Ӵ���״����ʱ��ֻ֪����������£�������͡��Ĺ��ܣ�û�뵽���С�������£������ѯ�������á�

��һ��
��״������������;����һά��״�����������
����1.������£������ѯ������ͣ�
���������������ʱ��������������c[n]����չ
���������������ѯʱ������Ҷ�ӽڵ㣨��c[1]����չ
����2.������£������ѯ
���������������ʱ������Ҷ�ӽڵ㣨��c[1]����չ
�������������ѯʱ������������c[n]����չ

(��������ο�http://www.cnblogs.com/chenxiwenruo/p/3430920.html)
����������ֻ��������update()��query()�����е�+��-�滻һ�¶��ѡ�
�޸�[a, b]��ʹ������+1:
update(b,1);
update(a-1,-1);
��ѯ��p
query(p)

������
��ʵҲ���������������һ��Ĳ�ѯ�Ͳ�����࣬����ע����θ��½ڵ㡣
����������ο�http://blog.csdn.net/kenden23/article/details/29854527��
update��query����
�޸�[a, b]��ʹ������+1:
update(a,1);
update(b+1,-1);
��ѯ��p
query(p)