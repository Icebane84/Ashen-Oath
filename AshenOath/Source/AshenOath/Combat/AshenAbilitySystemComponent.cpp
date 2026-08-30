// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenAbilitySystemComponent.h"
#include "AshenGameplayAbility.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenAbilitySystemComponent::UAshenAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentSanity = 100.0f;
	CurrentPoise = 100.0f;
	CurrentStamina = 100.0f;
}

void UAshenAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenAbilitySystemComponent::AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire)
{
	if (AbilityToAcquire)
	{
		GiveAbility(FGameplayAbilitySpec(AbilityToAcquire, 1));
	}
}

void UAshenAbilitySystemComponent::OnAttributeChange(const FOnAttributeChangeData& Data)
{
	// Internal attribute routing
}

void UAshenAbilitySystemComponent::OnGameplayEffectAppliedToSelf(UAbilitySystemComponent* Source, const FGameplayEffectSpec& SpecApplied, FActiveGameplayEffectHandle ActiveHandle)
{
	FGameplayTagContainer AssetTags;
	SpecApplied.GetAllAssetTags(AssetTags);

	// Log effect application with escaped format strings per UE 5.8 standards
	UE_LOG(LogTemp, Verbose, TEXT("AshenAbilitySystemComponent: GameplayEffect applied with %d tags."), AssetTags.Num());
}

void UAshenAbilitySystemComponent::ApplySanityDamage(float Amount)
{
	if (Amount <= 0.0f)
	{
		return;
	}

	const float OldSanity = CurrentSanity;
	CurrentSanity = FMath::Clamp(CurrentSanity - Amount, 0.0f, MaxSanity);
	OnSanityChanged.Broadcast(CurrentSanity);

	// Commit canonical deltas: Sanity loss increases Dysregulation (N/Isolation) & Corruption (C)
	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		const float NormalizedLoss = (OldSanity - CurrentSanity) / FMath::Max(1.0f, MaxSanity);

		FSoulStateVector Delta;
		Delta.Resolve = 0.0f;
		Delta.Corruption = NormalizedLoss * 0.50f;
		Delta.IntegrationDebt = 0.0f;
		Delta.Isolation = NormalizedLoss * 0.60f; // Canonical Dysregulation (N)
		Delta.GarrettTrust = 0.0f;
		Delta.SerafinaTrust = 0.0f;

		Publisher->CommitState(Delta);
	}
}

void UAshenAbilitySystemComponent::ApplyPoiseStrain(float Amount)
{
	if (Amount <= 0.0f)
	{
		return;
	}

	const float OldPoise = CurrentPoise;
	CurrentPoise = FMath::Clamp(CurrentPoise - Amount, 0.0f, MaxPoise);
	OnPoiseChanged.Broadcast(CurrentPoise);

	// Heavy poise strain converts guard impact directly into Integration Debt (D)
	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		const float NormalizedStrain = (OldPoise - CurrentPoise) / FMath::Max(1.0f, MaxPoise);

		FSoulStateVector Delta;
		Delta.Resolve = 0.0f;
		Delta.Corruption = 0.0f;
		Delta.IntegrationDebt = NormalizedStrain * 0.40f;
		Delta.Isolation = 0.0f;
		Delta.GarrettTrust = 0.0f;
		Delta.SerafinaTrust = 0.0f;

		Publisher->CommitState(Delta);
	}
}

void UAshenAbilitySystemComponent::ApplyStaminaDrain(float Amount)
{
	if (Amount <= 0.0f)
	{
		return;
	}

	CurrentStamina = FMath::Clamp(CurrentStamina - Amount, 0.0f, MaxStamina);
	OnStaminaChanged.Broadcast(CurrentStamina);

	// Stamina exhaustion (< 40%) triggers cardiac tension telemetry
	if (CurrentStamina < 40.0f)
	{
		UE_LOG(LogTemp, Verbose, TEXT("AshenAbilitySystemComponent: Stamina low (%f/100) -- cardiac drag armed."), CurrentStamina);
	}
}

UAshenSoulPublisher* UAshenAbilitySystemComponent::GetSoulPublisher() const
{
	if (const UWorld* World = GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			return GI->GetSubsystem<UAshenSoulPublisher>();
		}
	}
	return nullptr;
}
