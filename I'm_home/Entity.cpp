#include "Entity.h"
extern char map[MAP_SIZE][MAP_SIZE];
Entity GenerateEntity(int quad, Object_Type obj_type)
{
    Entity entity;
    int x, y;

    while (true) {
        // quad  x    y
        // 1:   0~4, 0~4
        // 2:   5~9, 0~4
        // 3:   0~4, 5~9
        // 4:   5~9, 5~9

        if (quad % 2) { // quad: 1, 3
            x = rand() % 5;
            y = (quad / 2 == 0) ? rand() % 5 : rand() % 5 + 5;
        }
        else { // quad: 2, 4
            x = rand() % 5 + 5;
            y = (quad / 2 == 1) ? rand() % 5 : rand() % 5 + 5;
        }

        if (map[y][x] == (char)Object_Type::STREET) break;
    }
    
    entity.x = x;
    entity.y = y;
    entity.entity_type = obj_type;

    map[y][x] = (char)entity.entity_type;
    return entity;
}

/// <summary>
/// ��ƼƼ�� �̵���Ű�� �Լ�. isAuto�� value�� ���� �ڵ�, ���� �̵��� ������.
/// </summary>
/// <param name="entity">������ ��ƼƼ</param>
/// <param name="map">��ƼƼ�� �ִ� ��</param>
/// <param name="isAuto">������ ����</param>
void Move(Entity &entity, bool isAuto)
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
                map[entity.y][entity.x] = (char)Object_Type::STREET;
                entity += moveDir;

                map[entity.y][entity.x] = (char)entity.entity_type;
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
