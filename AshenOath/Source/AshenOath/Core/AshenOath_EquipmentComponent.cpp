// Copyright Phoenix Protocol. All rights reserved.

#include "AshenOath_EquipmentComponent.h"
#include "AshenSocketNames.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "AshenOath_HurtboxComponent.h"

UAshenOath_EquipmentComponent::UAshenOath_EquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	DefaultWeaponSocket = AshenSockets::Hand_R;
	SpawnedWeapon = nullptr;
}

void UAshenOath_EquipmentComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenOath_EquipmentComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UnequipWeapon();
	Super::EndPlay(EndPlayReason);
}

void UAshenOath_EquipmentComponent::EquipWeapon(TSubclassOf<AAshenWeaponActor> WeaponClass)
{
	if (!WeaponClass || !GetWorld()) return;

	// Clear existing weapon first
	if (SpawnedWeapon)
	{
		UnequipWeapon();
	}

	ACharacter* OwnerChar = Cast<ACharacter>(GetOwner());
	if (!OwnerChar) return;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = OwnerChar;
	SpawnParams.Instigator = OwnerChar;

	AAshenWeaponActor* NewWeapon = GetWorld()->SpawnActor<AAshenWeaponActor>(
		WeaponClass,
		FVector::ZeroVector,
		FRotator::ZeroRotator,
		SpawnParams
	);

	if (NewWeapon)
	{
		// Attach to owner's skeletal mesh
		NewWeapon->AttachToComponent(
			OwnerChar->GetMesh(),
			FAttachmentTransformRules::SnapToTargetIncludingScale,
			DefaultWeaponSocket
		);

		// Synchronize team ID from character's hurtbox
		if (UAshenOath_HurtboxComponent* Hurtbox = OwnerChar->FindComponentByClass<UAshenOath_HurtboxComponent>())
		{
			NewWeapon->SetWeaponTeamId(Hurtbox->GetTeamId());
		}

		SpawnedWeapon = NewWeapon;
		OnWeaponEquipped.Broadcast(SpawnedWeapon);
	}
}

void UAshenOath_EquipmentComponent::UnequipWeapon()
{
	if (SpawnedWeapon)
	{
		SpawnedWeapon->Destroy();
		SpawnedWeapon = nullptr;
		OnWeaponEquipped.Broadcast(nullptr);
	}
}
