#include "global.h"
#include "entity.h"
#include "sprite.h"
#include "functions.h"
#include "enemy.h"

extern void (*const gUnk_080012C8[])(Entity*);
extern void (*const gUnk_080CF4C8[6])(Entity*);
extern void (*const gUnk_080CF4E0[4])(Entity*);

extern s32 sub_080012DC(Entity*);
extern void SetGlobalFlag(u32);
extern u32 CheckGlobalFlag(u32);
extern u32 sub_0804A044(Entity*, Entity*, u32);

void sub_080383AC(Entity*);
void sub_080383E4(Entity*);

void RopeGolden(Entity* this) {
    u32 x;
    x = sub_080012DC(this);
    if (x != 0) {
        gUnk_080012C8[x](this);
    } else {
        gUnk_080CF4C8[GetNextFunction(this)](this);
        SetChildOffset(this, 0, 1, -0x10);
    }
}

void RopeGolden_OnTick(Entity* this) {
    gUnk_080CF4E0[this->action](this);
}

void sub_08038210(Entity* this) {
    if (this->field_0x43 != 0) {
        sub_0804A9FC(this, 0x1c);
    }
    sub_0804AA30(this, gUnk_080CF4C8);
}

void sub_08038234(Entity* this) {
    if ((this->field_0x3a & 2) == 0) {
        SetGlobalFlag(this->type2);
    }
    CreateDeathFx(this, 0xff, 0x58);
}

void sub_08038258(Entity* this) {
    if (CheckGlobalFlag(this->type2) != 0) {
        DeleteThisEntity();
    }
    sub_0804A720(this);
    this->animationState = 0xff;
    sub_080383AC(this);
}

void sub_0803827C(Entity* this) {
    if (this->field_0xf != 0) {
        this->field_0xf--;
    } else {
        if ((sub_0804A044(this, &gPlayerEntity, 0x8) != 0xff) ||
            (sub_0806FCB8(this, gPlayerEntity.x.HALF.HI, gPlayerEntity.y.HALF.HI, 0x24) != 0)) {
            sub_080383E4(this);
            return;
        }
    }
    UpdateAnimationVariableFrames(this, 0x2);
    if (ProcessMovement(this) == 0) {
        sub_080383AC(this);
    } else {
        if (!(--this->actionDelay)) {
            sub_080383AC(this);
        }
    }
}

void sub_080382EC(Entity* this) {
    if (!(--this->actionDelay)) {
        this->action = 3;
    }
}

ASM_FUNC("asm/non_matching/ropeGolden/sub_08038304.inc", void sub_08038304(Entity* this))

void sub_080383AC(Entity* this) {
    u32 v;
    this->action = 1;
    this->actionDelay = 0x8;
    this->speed = 0x100;
    this->direction = DirectionRoundUp(GetFacingDirection(this, &gPlayerEntity));
    v = this->direction >> 3;
    if (v != this->animationState) {
        this->animationState = v;
        InitializeAnimation(this, v);
    }
}

void sub_080383E4(Entity* this) {
    u32 v;
    this->action = 2;
    this->actionDelay = 0x8;
    this->speed = 0x280;
    v = DirectionRoundUp(GetFacingDirection(this, &gPlayerEntity));
    this->direction = v;
    this->field_0x78.HALF.LO = v;
    this->animationState = this->direction >> 3;
    this->field_0x78.HALF.HI = 0xff;
    this->field_0x7a.HALF.LO = -1;
    InitializeAnimation(this, this->animationState + 4);
}
