#include "Entity.h"

/// <summary>
/// ��ƼƼ�� �̵���Ű�� �Լ�. isAuto�� value�� ���� �ڵ�, ���� �̵��� ������.
/// </summary>
/// <param name="entity">������ ��ƼƼ</param>
/// <param name="map">��ƼƼ�� �ִ� ��</param>
/// <param name="isAuto">������ ����</param>
void Move(Entity &entity, char map[MAP_SIZE][MAP_SIZE], bool isAuto)
{
    COORD     moveDir   = {0, 0}; // Vector2.zero
    
    if (isAuto) {
        // ���� �õ� ����
        srand(time(NULL));
        
        Direction randomDir = (Direction)(rand() % 4); // up, down, left, right

        while (true) {
            // ���� �̵� ���� ����
            if (randomDir == Direction::UP    && entity.y > 0) moveDir = { 0,-1 };
            if (randomDir == Direction::DOWN  && entity.y < 9) moveDir = { 0, 1 };
            if (randomDir == Direction::LEFT  && entity.x > 0) moveDir = {-1, 0 };
            if (randomDir == Direction::RIGHT && entity.x < 9) moveDir = { 1, 0 };

            // �̵� �������� �̵� ���� ���� �Ǵ�
            if (map[entity.y + moveDir.Y][entity.x + moveDir.X] == (int)Object_Type::STREET) {
                // ��ƼƼ �̵�
                entity += moveDir;
                break;
            }
        }
    }
    else {
        while (true) {
            // Ű���� ����Ű �Է�
            char key = _getch();

            COORD     moveDir = { 0, 0 };
       
            if (key == 72 && entity.y > 0) moveDir = {  0,-1 };
            if (key == 80 && entity.y < 9) moveDir = {  0, 1 };
            if (key == 75 && entity.x > 0) moveDir = { -1, 0 };
            if (key == 77 && entity.x < 9) moveDir = {  1, 0 };

            if (map[entity.y + moveDir.Y][entity.x + moveDir.X] == (int)Object_Type::STREET) {
                entity += moveDir;
                break;
            }
        }
    }
}
