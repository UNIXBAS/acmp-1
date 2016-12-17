#include <iostream>

using namespace std;

// �������� �� ������ 3
// ������������ ��� c������� ��� � ����� = +1: AddMod3(op1, 1)
// ��� � � ����� = -1:   AddMod3(op1, 2)
inline unsigned AddMod3(unsigned op1, unsigned op2)
{
    return  ((op1 + op2) % 3);
}

// �������� ������ �������
struct Pivot {
    unsigned disk_number; // ������� ���������� ������ �� �������
    unsigned *disk_list;  // ������ ������, ����������� �� �������
};

// ����� �� ���� ��������
struct Pivots {
    Pivot pivot[3];
    Pivots(unsigned disks); // ��������� ������������ ��������
    ~Pivots(); // "����������" �������� �� ���������� ����������
};

// ��������� ������������ ��������
Pivots::Pivots(unsigned disks)
{
    // ��������� ����� ��� �������� ������
    for(int i = 0; i < 3; i++) {
        pivot[i].disk_list = new unsigned[disks+1];
        pivot[i].disk_number = 0;
        // ��������, ������������� ��� ������� ����� ������
        pivot[i].disk_list[0] = disks + 1;
    }

    // ������� �������� ����������� ������� ����� �������,
    // ����� ����� ����� �������� � ��������
    for(int i = 1; i <= disks; i++) {
        pivot[0].disk_list[i] = disks - i + 1;
    }
    pivot[0].disk_number = disks;
}

// "����������" �������� �� ���������� ����������
Pivots::~Pivots()
{
    for(int i = 0; i < 3; i++)
        delete[] pivot[i].disk_list;
}

// ������ ����������� �� ������������ ����
inline void out(unsigned count, unsigned src, unsigned rec, Pivots &p)
{
    cout << count << ":\t " << src << " -> " << rec
         << "\t\t pivots: "
         << p.pivot[0].disk_number << "\t"
         << p.pivot[1].disk_number << "\t"
         << p.pivot[2].disk_number << "\t"
         << " Disk = "
         << p.pivot[rec].disk_list[p.pivot[rec].disk_number]
         << endl;
}

inline void move(unsigned src, unsigned rec,
Pivots &p, unsigned &count)
{
    p.pivot[rec].disk_list[++p.pivot[rec].disk_number] =
        p.pivot[src].disk_list[p.pivot[src].disk_number--];
    out(++count, src, rec, p);
}

// ��������, �������������� ������������� ��������� �����
void hanoy(unsigned disks)
{
    unsigned count = 0; // ������� �������������� ������
    // ���, ������������ ����������� �������� ����� (1 ��� 2)
    // ��� �������� �� �������� ������������ ������������
    unsigned step = 1 + (disks & 1);
    // ��� ����������� ��������������� �������, �� �������,
    // ��� � �������� (����� ���������) ������������ ��������� ����
    // ��� ����������� ����� ���� ���������� ������� �������� ��� �� 3
    unsigned alt_step = 3 - step;
    // ������� � �������
    Pivots p(disks);

    // �������� ������� ������
    if(disks < 1)
    {
        cout << "Disks are absent!" << endl;
        return;
    }

    // ������ �������� ������ ����������� �����
    unsigned src = 0;
    unsigned rec = step;
    move(src, rec, p, count);

    if(disks < 2) return; // ����� ������������� ����� �� 1-�� �����

    // ������� ������� ����� � ��������� ����������� �����
    unsigned alt = AddMod3(src, alt_step);
    move(src, alt, p, count);

    // ���������� ������������� ����������� �����
    src = rec;
    rec = AddMod3(src, step);
    move(src, rec, p, count);

    if(disks < 3) return; // ����� ������������� ����� �� 2-� ������

    // ����� ������� ��������, ���������� �� 4 ������� ����.
    // ���������� ���� �� ��� ��� ����� ������ ������ ����.

    // ������ ������ �����
    //unsigned iterations = (1 << (disks - 2)) - 1; // ����� ��������
    //for(unsigned i = 0; i < iterations; ++i)
    // ����� �������� �� ��������� ����������,
    // ��������� ���������� ������ �� �������.
    while(p.pivot[2].disk_number < disks)
    {
        // ������������ ������ ����������
        // ������� ���� ��������������� �� �������
        // ��������� �������� � �������������� �������
        // ����� �������������� �������� �� ������ ����
        // ���������� ����������
        alt = AddMod3(src, alt_step);
        if(    p.pivot[src].disk_list[p.pivot[src].disk_number] >
            p.pivot[alt].disk_list[p.pivot[alt].disk_number]
          )
        {
            // � ��������������� �� ��������
            move(alt, src, p, count);
            //p.pivot[src].disk_list[++p.pivot[src].disk_number] =
            //    p.pivot[alt].disk_list[p.pivot[alt].disk_number--];
            //out(++count, alt, src, p);
        }
        else
        {
            // � ��������� �� ��������������
            move(src, alt, p, count);
        }
        // ������ �������� ����������� �����
        src = rec;    // ������� �������� ���������� ����������
        rec = AddMod3(src, step); // ����� ��������
        move(src, rec, p, count);

        // ������� ������� ����� � ��������� ����������� �����
        alt = AddMod3(src, alt_step); // ����� �������������� ��������
        move(src, alt, p, count);

        // ���������� ������������� ����������� �����
        src = rec;    // ������� �������� ���������� ����������
        rec = AddMod3(src, step); // ����� ��������
        move(src, rec, p, count);
    }

    cout << endl
         << "Used "
         << disks      << " disks. "
         << endl
         << "Make "
         << count << " steps."
         << endl;
}

main()
{
    unsigned disks;
    cout << "Input disk\'s number: ";
    cin >> disks;
    cout << "Hanoy with " << disks <<" disks:" << endl;
    hanoy(disks);
}
