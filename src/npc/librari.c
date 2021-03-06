#include "global.h"
#include "entity.h"
#include "npc.h"
#include "flags.h"
#include "textbox.h"
#include "functions.h"

extern u16 gUnk_08112D48[];

void Librari(Entity* this) {
    switch (this->action) {
        case 0:
            this->action = 1;
            this->spriteSettings.b.draw = TRUE;
            this->animationState = this->actionDelay;
            this->field_0x68.HALF.LO = sub_0801E99C(this);
            sub_08078784(this, this->field_0x68.HALF.LO);
            sub_0805E3A0(this, 2);
            sub_0807DD50(this);
            break;
        case 1:
            if (this->interactType == 2) {
                this->action = 2;
                this->interactType = 0;
                sub_0806F118(this);
            } else {
                sub_0807DDAC(this, 0);
                sub_0807DDE4(this);
                UpdateAnimationSingleFrame(this);
            }
            break;
        case 2:
            if (UpdateFuseInteraction(this)) {
                this->action = 1;
            }
    }
}

void sub_0806B260(Entity* this, u32 arg1) {
    u32 index;

    *(u32*)(arg1 + 0x14) = 0;
    // flippers
    if (!GetInventoryValue(0x46)) {
        if (CheckGlobalFlag(0x29)) {
            index = 2;
            *(u32*)(arg1 + 0x14) = 1;
        } else if (!CheckLocalFlag(0x7a)) {
            index = 0;
            SetLocalFlag(0x7a);
        } else {
            index = 1;
        }
    } else {
        index = 3;
    }
    TextboxNoOverlap(gUnk_08112D48[index], this);
}

extern u16 gUnk_08112D50[];

void sub_0806b2b4(Entity* this) {
    u32 index;

    if (CheckLocalFlag(0xb3)) {
        if (!CheckRoomFlag(0)) {
            index = 1;
            SetRoomFlag(0);
        } else if (!CheckRoomFlag(1)) {
            index = 2;
            SetRoomFlag(1);
        } else if (!CheckRoomFlag(2)) {
            index = 3;
            SetRoomFlag(2);
        } else {
            index = 4;
            ClearRoomFlag(0);
            ClearRoomFlag(1);
            ClearRoomFlag(2);
        }
    } else {
        index = 0;
    }
    TextboxNoOverlap(gUnk_08112D50[index], this);
}

void Librari_Fusion(Entity *this)
{
  if (this->action == 0) {
    this->action++;
    this->spriteSettings.b.draw = TRUE;
    InitAnimationForceUpdate(this, 9);
  }
  else {
    UpdateAnimationSingleFrame(this);
  }
}

void Percy_Head(Entity *this) // ???
{
  SetExtraSpriteFrame(this, 0, (this->frameSpriteSettings & 0x3f) + 0x13);
  SetExtraSpriteFrame(this, 1, (this->frames.all & 0x7f) + 0xb);
  SetExtraSpriteFrame(this, 2, this->frameIndex);
  SetSpriteSubEntryOffsetData1(this, 2, 1);
  SetSpriteSubEntryOffsetData2(this, 2, 0);
  sub_0807000C(this);
}