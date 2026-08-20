// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 175: Ashen Serafina Aura Field Component

#include "AshenSerafinaAuraFieldComponent.h"
#include "AshenOath_HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "TimerManager.h"

UAshenSerafinaAuraFieldComponent::UAshenSerafinaAuraFieldComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	AuraRadius    = 450.0f;
	HealPerTick   = 12.0f;
	PulseInterval = 3.0f;
	MaxAlliesHealed = 8;
	bAuraActive   = false;
}

void UAshenSerafinaAuraFieldComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSerafinaAuraFieldComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	DeactivateAura();
}

void UAshenSerafinaAuraFieldComponent::ActivateAura()
{
	if (bAuraActive) return;
	bAuraActive = true;
	GetWorld()->GetTimerManager().SetTimer(
		AuraPulseTimer,
		this,
		&UAshenSerafinaAuraFieldComponent::PulseAuraHeal,
		PulseInterval,
		true
	);
	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaAuraFieldComponent: Holy Aura ACTIVATED — %.0f unit radius, %.0f HP per %.1fs tick."),
		AuraRadius, HealPerTick, PulseInterval);
}

void UAshenSerafinaAuraFieldComponent::DeactivateAura()
{
	if (!bAuraActive) return;
	bAuraActive = false;
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(AuraPulseTimer);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaAuraFieldComponent: Holy Aura DEACTIVATED."));
}

void UAshenSerafinaAuraFieldComponent::PulseAuraHeal()
{
	if (!bAuraActive || !GetOwner()) return;

	TArray<AActor*> OverlappingActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UKismetSystemLibrary::SphereOverlapActors(
		GetWorld(),
		GetOwner()->GetActorLocation(),
		AuraRadius,
		ObjectTypes,
		AActor::StaticClass(),
		TArray<AActor*>{},
		OverlappingActors
	);

	int32 AlliesHealed = 0;
	for (AActor* Target : OverlappingActors)
	{
		if (AlliesHealed >= MaxAlliesHealed) break;
		if (!Target) continue;

		UAshenOath_HealthComponent* HealthComp = Target->FindComponentByClass<UAshenOath_HealthComponent>();
		if (HealthComp)
		{
			HealthComp->Heal(HealPerTick);
			AlliesHealed++;
		}
	}

	OnAuraHealTick.Broadcast(HealPerTick);
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaAuraFieldComponent: Aura pulse — healed %d allies for %.0f HP each."),
		AlliesHealed, HealPerTick);
}
