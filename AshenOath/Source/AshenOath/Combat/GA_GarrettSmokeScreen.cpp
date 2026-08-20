// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 183: GA_GarrettSmokeScreen

#include "GA_GarrettSmokeScreen.h"
#include "Kismet/KismetSystemLibrary.h"

UGA_GarrettSmokeScreen::UGA_GarrettSmokeScreen()
{
	SmokeRadius = 500.0f;
	StealthDuration = 6.0f;
}

void UGA_GarrettSmokeScreen::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	AActor* Owner = ActorInfo->OwnerActor.Get();
	if (!Owner)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	const FVector Origin = Owner->GetActorLocation();

	TArray<AActor*> AffectedActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		Owner->GetWorld(),
		Origin,
		SmokeRadius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>(),
		AffectedActors
	);

	UE_LOG(LogTemp, Warning, TEXT("UGA_GarrettSmokeScreen: SMOKE SCREEN deployed at (%.0f, %.0f, %.0f) — %.0fs stealth granted to %d pawns in %.0fu radius."),
		Origin.X, Origin.Y, Origin.Z, StealthDuration, AffectedActors.Num(), SmokeRadius);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
