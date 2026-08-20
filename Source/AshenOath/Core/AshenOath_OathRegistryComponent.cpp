// AshenOath_OathRegistryComponent.cpp
// Copyright Ashen Oath. All rights reserved.

#include "AshenOath_OathRegistryComponent.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "AshenSoulConstellationSubsystem.h"
#include "AshenOath_DirectorSubsystem.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

DEFINE_LOG_CATEGORY(LogAshenOathRegistry);

UAshenOath_OathRegistryComponent::UAshenOath_OathRegistryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	OathBurden = 0.0f;
	BurdenPerOath = 0.1f;
}

void UAshenOath_OathRegistryComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenOath_OathRegistryComponent::SwearOath(FName OathID, FText Description)
{
	if (OathID.IsNone())
	{
		return false;
	}

	// Prevent duplicate oath IDs
	for (const FOathRecord& Existing : Oaths)
	{
		if (Existing.OathID == OathID)
		{
			UE_LOG(LogAshenOathRegistry, Warning, TEXT("SwearOath: Oath '%s' already sworn."), *OathID.ToString());
			return false;
		}
	}

	FOathRecord NewOath;
	NewOath.OathID = OathID;
	NewOath.OathDescription = Description;
	NewOath.bFulfilled = false;
	NewOath.bBroken = false;
	NewOath.TimeSinceSworn = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;

	Oaths.Add(NewOath);
	OathBurden = FMath::Clamp(OathBurden + BurdenPerOath, 0.0f, 2.0f);

	UE_LOG(LogAshenOathRegistry, Log, TEXT("SwearOath: Sworn '%s'. Total Oaths: %d | Burden: %.2f"),
		*OathID.ToString(), Oaths.Num(), OathBurden);

	OnOathSworn.Broadcast(NewOath);
	return true;
}

bool UAshenOath_OathRegistryComponent::FulfillOath(FName OathID)
{
	FOathRecord* Found = Oaths.FindByPredicate([OathID](const FOathRecord& Rec) { return Rec.OathID == OathID; });
	if (!Found || Found->bFulfilled || Found->bBroken)
	{
		return false;
	}

	Found->bFulfilled = true;

	// Heal sanity +20 on oath fulfillment
	if (AActor* Owner = GetOwner())
	{
		if (UAshenOath_SanityComponent* Sanity = Owner->FindComponentByClass<UAshenOath_SanityComponent>())
		{
			Sanity->HealSanity(20.0f);
		}

		if (UAshenOath_ImprintBufferComponent* Buffer = Owner->FindComponentByClass<UAshenOath_ImprintBufferComponent>())
		{
			Buffer->AddImprint(EImprintType::Oath, 0.10f); // Positive identity imprint
		}
	}

	UE_LOG(LogAshenOathRegistry, Log, TEXT("FulfillOath: Oath '%s' FULFILLED! Sanity healed."), *OathID.ToString());

	OnOathFulfilled.Broadcast(*Found);
	return true;
}

bool UAshenOath_OathRegistryComponent::BreakOath(FName OathID)
{
	FOathRecord* Found = Oaths.FindByPredicate([OathID](const FOathRecord& Rec) { return Rec.OathID == OathID; });
	if (!Found || Found->bFulfilled || Found->bBroken)
	{
		return false;
	}

	Found->bBroken = true;

	if (AActor* Owner = GetOwner())
	{
		// Suffer 25 mental damage on oath breach
		if (UAshenOath_SanityComponent* Sanity = Owner->FindComponentByClass<UAshenOath_SanityComponent>())
		{
			Sanity->SufferMentalDamage(25.0f);
		}

		// Add heavy Oath imprint (0.35f) to session buffer
		if (UAshenOath_ImprintBufferComponent* Buffer = Owner->FindComponentByClass<UAshenOath_ImprintBufferComponent>())
		{
			Buffer->AddImprint(EImprintType::Oath, 0.35f);
		}
	}

	UE_LOG(LogAshenOathRegistry, Warning, TEXT("BreakOath: Oath '%s' BROKEN! Mental damage 25 applied."), *OathID.ToString());

	OnOathBroken.Broadcast(*Found);
	return true;
}

int32 UAshenOath_OathRegistryComponent::GetBrokenOathCount() const
{
	int32 Count = 0;
	for (const FOathRecord& Rec : Oaths)
	{
		if (Rec.bBroken)
		{
			Count++;
		}
	}
	return Count;
}

int32 UAshenOath_OathRegistryComponent::GetActiveOathCount() const
{
	int32 Count = 0;
	for (const FOathRecord& Rec : Oaths)
	{
		if (!Rec.bFulfilled && !Rec.bBroken)
		{
			Count++;
		}
	}
	return Count;
}

void UAshenOath_OathRegistryComponent::LoadOathState(const TArray<FOathRecord>& SavedOaths, float SavedBurden)
{
	Oaths = SavedOaths;
	OathBurden = FMath::Clamp(SavedBurden, 0.0f, 2.0f);
	UE_LOG(LogAshenOathRegistry, Log, TEXT("LoadOathState: Restored %d oaths. Burden: %.2f"), Oaths.Num(), OathBurden);
}
