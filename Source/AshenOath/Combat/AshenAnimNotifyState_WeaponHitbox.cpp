// Copyright Phoenix Protocol. All rights reserved.

#include "AshenAnimNotifyState_WeaponHitbox.h"
#include "Components/SkeletalMeshComponent.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_EquipmentComponent.h"
#include "AshenWeaponActor.h"
#include "GameFramework/Actor.h"

void UAshenAnimNotifyState_WeaponHitbox::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (!MeshComp) return;

	AActor* OwnerActor = MeshComp->GetOwner();
	if (OwnerActor && OwnerActor->Implements<UAshenCharacterInterface>())
	{
		UAshenOath_EquipmentComponent* Equipment = IAshenCharacterInterface::Execute_GetEquipmentComponent(OwnerActor);
		if (Equipment)
		{
			AAshenWeaponActor* Weapon = Equipment->GetEquippedWeapon();
			if (Weapon)
			{
				Weapon->ActivateWeapon();
			}
		}
	}
}

void UAshenAnimNotifyState_WeaponHitbox::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (!MeshComp) return;

	AActor* OwnerActor = MeshComp->GetOwner();
	if (OwnerActor && OwnerActor->Implements<UAshenCharacterInterface>())
	{
		UAshenOath_EquipmentComponent* Equipment = IAshenCharacterInterface::Execute_GetEquipmentComponent(OwnerActor);
		if (Equipment)
		{
			AAshenWeaponActor* Weapon = Equipment->GetEquippedWeapon();
			if (Weapon)
			{
				Weapon->DeactivateWeapon();
			}
		}
	}
}
