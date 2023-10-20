#include "./include/Role.h"

Role::Role(float _hp, float _att, float _def)      /*参数化构造函数*/
{
    hp = _hp;
    attack = _att;
    defence = _def;
}

Role::Role(const Role & _role)
{
    hp = _role.hp;
    attack = _role.attack;
    defence = _role.defence;
}

Role::Role(Role && _role) : hp(_role.hp), attack(_role.attack), defence(_role.defence)
{
    _role.hp = 0;
    _role.attack = 0;
    _role.defence = 0;
}

void Role::getter() const
{
    using std::cout, std::endl;

    cout << "Hp: " << hp << endl;
    cout << "Attact: " << attack << endl;
    cout << "Defence: " << defence << endl;
}

bool Role::setter(float _hp, float _att, float _def)
{
    if (_hp < 0 || _att < 0 || _def < 0)
    {
        std::cout << "Invalid modifications...." << std::endl;
        return false;
    }

    hp = _hp;
    attack = _att;
    defence = _def;

    return true;
}

/* 1 防御 可以抵消 5 点生命*/
float Role::Get_Total_Life() const
{
    return hp + defence * _DEFENSE;
}

Role & Role::operator=(const Role & _role)
{
    if (this == &_role) { return *this; }

    hp = _role.hp;
    attack = _role.attack;
    defence = _role.defence;

    return *this;
}

void Role::logic(float _damage)
{
    float _actual_damage = _damage - defence / _DEFENSE;

    _actual_damage = (_actual_damage > 0) ? _actual_damage : 0;

    hp -= _actual_damage;

    hp = (hp < 0) ? 0 : hp; 
}