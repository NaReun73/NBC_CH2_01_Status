// Main.cpp

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
void addPotion(int count, int* p_HPPotion, int* p_MPPotion);

void addAbility(int vStatus[]);

int main(void)
{
	int Status[7] = { 0, };
	int Ability = 0;
	int Num;
	int Level = 1;

	int HpPotion = 0;
	int MpPotion = 0;

	bool Spawn = false;

	srand(time(0));

	while (Spawn != true)
	{
		while (true)
		{
			cout << "HP/MP를 입력해주세요.(50이하는 안됩니다.)" << endl;
			cin >> Status[0] >> Status[1];

			if (Status[0] <= 50 || Status[1] <= 50)
			{
				cout << "HP 또는 MP 값이 50이하입니다. 다시 입력해주세요." << endl;
			}

			else
			{
				cout << "설정되었습니다." << endl;
				break;
			}
		}

		while (true)
		{
			cout << "공격력과 방어력을 입력해주세요.(0이하는 안됩니다.)" << endl;
			cin >> Status[2] >> Status[3];

			if (Status[2] <= 0 || Status[3] <= 0)
			{
				cout << "공격력 또는 방어력 값이 0이하입니다. 다시 입력해주세요." << endl;
			}

			else
			{
				cout << "설정되었습니다." << endl;
				break;
			}
		}

		for (int i = 4; i < 7; ++i)
		{
			Ability = rand() % 10 + 1;
			Status[i] = Ability;
		}
		
		cout << "캐릭터를 생성합니다." << endl;
		setPotion(5, &HpPotion, &MpPotion);
		Spawn = true;
	}

	while (Spawn)
	{
		cout << "1.HP UP / 2,MP UP / 3.공격력 UP / 4.방어력 UP / 5.현재 능력치 / 6.Level UP / 7.포션 보충 / 0.나가기 " << endl;
		cin >> Num;

		if (Num == 1)
		{
			if (HpPotion != 0)
			{
				Status[0] += 20;
				HpPotion -= 1;

				cout << "HP UP!" << endl;
				cout << "현재 HP : " << Status[0] << endl;
				cout << "남은 HP포션 : " << HpPotion << endl;
			}
			else
			{
				cout << "HP 포션이 없습니다." << endl;
			}
		}

		else if (Num == 2)
		{
			if (MpPotion != 0)
			{
				Status[1] += 20;
				MpPotion -= 1;

				cout << "MP UP!" << endl;
				cout << "현재 MP : " << Status[1] << endl;
				cout << "남은 MP포션 : " << MpPotion << endl;
			}
			else
			{
				cout << "MP 포션이 없습니다." << endl;
			}
		}

		else if (Num == 3)
		{
			cout << "공격력 2배 증가!" << endl;
			Status[2] *= 2;
			//Status[2] += Status[2];
			cout << "현재 공격력 : " << Status[2] << endl;
		}

		else if (Num == 4)
		{
			cout << "방어력 2배 증가!" << endl;
			Status[2] *= 2;
			//Status[3] += Status[3];
			cout << "현재 방어력 : " << Status[3] << endl;
		}

		else if (Num == 5)
		{
			cout << "---현재 능력치---" << endl;
			cout << "현재 레벨 : " << Level << endl;
			cout << "HP : " << Status[0] << endl;
			cout << "MP : " << Status[1] << endl;
			cout << "공격력 : " << Status[2] << endl;
			cout << "방어력 : " << Status[3] << endl;
			cout << "크리티컬 : " << Status[4] << endl;
			cout << "밸런스 : " << Status[5] << endl;
			cout << "공격속도 : " << Status[6] << endl;
			cout << "남은 HP포션 : " << HpPotion << endl;
			cout << "남은 MP포션 : " << MpPotion << endl;
		}

		else if (Num == 6)
		{
			cout << "Level UP!" << endl;
			cout << "레벨 : "  << Level << " -> " << ++Level << endl;
			cout << "포션을 1개씩 지급합니다." << endl;
			addPotion(1, &HpPotion, &MpPotion);

			cout << "추가 능력치를 얻습니다." << endl;
			addAbility(Status);
		}

		else if (Num == 7)
		{
			int p = 0;
			cout << "포션을 보충합니다." << endl;
			cout << "갯수 : ";
			cin >> p;
			addPotion(p, &HpPotion, &MpPotion);
		}

		else if (Num == 0)
		{
			cout << "종료되었습니다" << endl;
			break;
		}

		else
		{
			cout << "잘못된 입력입니다." << endl;
			cout << "입력값 : " << Num << endl;
		}
	}
	

	return 0;
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	cout << "HP포션, MP포션 각각 " << count << "개씩 지급되었습니다." << endl;
	*p_HPPotion = count;
	*p_MPPotion = count;

	cout << "총 HP포션 : " << *p_HPPotion << "개" << endl;
	cout << "총 MP포션 : " << *p_MPPotion << "개" << endl;

	return;
}

void addPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	cout << "HP포션, MP포션 각각 " << count << "개씩 보충되었습니다." << endl;
	*p_HPPotion += count;
	*p_MPPotion += count;

	cout << "총 HP포션 : " << *p_HPPotion << "개" << endl;
	cout << "총 MP포션 : " << *p_MPPotion << "개" << endl;

	return;
}

void addAbility(int vStatus[])
{
	int vNum = 0;
	int vAbilty = 0;
	int save[3] = { 0, };
	
	for (int i = 0; i < 3;)
	{
		bool isSame = false;
		vNum = rand() % 7;
		for (int j = 0; j < 3; ++j)
		{
			if (vNum == save[j])
			{
				isSame = true;
				break;
			}
		}
		
		if (isSame != true)
		{
			save[i] = vNum;
			++i;
		}
	}

	for (int k = 0; k < 3; ++k)
	{
		vAbilty = rand() & 8 + 3;

		if (save[k] <= 3)
		{
			vAbilty *= 10;
			vStatus[save[k]] += vAbilty;
		}
		else
		{
			vStatus[save[k]] += vAbilty;
		}
	}
	return;
}