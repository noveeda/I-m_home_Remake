#include "Entity.h"

/// <summary>
/// 엔티티를 이동시키는 함수. isAuto의 value에 따라 자동, 수동 이동이 정해짐.
/// </summary>
/// <param name="entity">움직일 엔티티</param>
/// <param name="map">엔티티가 있는 맵</param>
/// <param name="isAuto">오토모드 여부</param>
void Move(Entity &entity, char map[MAP_SIZE][MAP_SIZE], bool isAuto)
{
    COORD     moveDir   = {0, 0}; // Vector2.zero
    
    if (isAuto) {
        // 랜덤 시드 생성
        srand(time(NULL));
        
        Direction randomDir = (Direction)(rand() % 4); // up, down, left, right

        while (true) {
            // 랜덤 이동 방향 결정
            if (randomDir == Direction::UP    && entity.y > 0) moveDir = { 0,-1 };
            if (randomDir == Direction::DOWN  && entity.y < 9) moveDir = { 0, 1 };
            if (randomDir == Direction::LEFT  && entity.x > 0) moveDir = {-1, 0 };
            if (randomDir == Direction::RIGHT && entity.x < 9) moveDir = { 1, 0 };

            // 이동 방향으로 이동 가능 여부 판단
            if (map[entity.y + moveDir.Y][entity.x + moveDir.X] == (int)Object_Type::STREET) {
                // 엔티티 이동
                entity += moveDir;
                break;
            }
        }
    }
    else {
        while (true) {
            // 키보드 방향키 입력
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
