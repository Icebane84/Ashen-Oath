// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSerafinaSacredBarrierGASAbility.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"

UAshenSerafinaSacredBarrierGASAbility::UAshenSerafinaSacredBarrierGASAbility()
{
	SanctuaryFieldClass = AAshenSanctuaryField::StaticClass();
}

AAshenSanctuaryField* UAshenSerafinaSacredBarrierGASAbility::SpawnSacredBarrier(FVector TargetLocation)
{
	AActor* Avatar = GetAvatarActorFromActorInfo();
	if (!Avatar)
	{
		Avatar = Cast<AActor>(GetOuter());
	}

	UWorld* World = Avatar ? Avatar->GetWorld() : nullptr;
	if (!World)
	{
		return nullptr;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	UClass* FieldToSpawn = SanctuaryFieldClass ? *SanctuaryFieldClass : AAshenSanctuaryField::StaticClass();
	AAshenSanctuaryField* SpawnedField = World->SpawnActor<AAshenSanctuaryField>(FieldToSpawn, TargetLocation, FRotator::ZeroRotator, SpawnParams);

	if (SpawnedField)
	{
		// Accumulate fatigue on Serafina
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenCompanionFatigueSubsystem* FatigueSubsystem = GI->GetSubsystem<UAshenCompanionFatigueSubsystem>())
			{
				FatigueSubsystem->AccumulateFatigue(FName(TEXT("Serafina")), 0.20f);
			}
		}

		UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaSacredBarrierGASAbility: Spawned Sanctuary Barrier at %s (+0.20 Serafina fatigue)."),
			*TargetLocation.ToString());
	}

	return SpawnedField;
}
