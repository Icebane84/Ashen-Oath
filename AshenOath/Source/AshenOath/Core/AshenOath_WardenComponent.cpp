// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenOath_WardenComponent.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

UAshenOath_WardenComponent::UAshenOath_WardenComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentBurnout = 0.0f;
	MaxBurnout = 100.0f;
	BurnoutDissipationRate = 2.5f;
}

void UAshenOath_WardenComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenOath_WardenComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Passive burnout dissipation when not overwhelmed
	if (CurrentBurnout > 0.0f)
	{
		CurrentBurnout = FMath::Clamp(CurrentBurnout - (BurnoutDissipationRate * DeltaTime), 0.0f, MaxBurnout);
		OnBurnoutLevelChanged.Broadcast(CurrentBurnout, MaxBurnout);
	}
}

bool UAshenOath_WardenComponent::CastSunPulse(float Radius)
{
	if (IsBurnoutExhausted())
	{
		UE_LOG(LogTemp, Warning, TEXT("CastSunPulse failed: Serafina is in Empathic Burnout exhaustion!"));
		return false;
	}

	AActor* Owner = GetOwner();
	const FVector PulseLocation = Owner ? Owner->GetActorLocation() : FVector::ZeroVector;

	// Sun Pulse adds 15 points of empathic transference burnout to Serafina
	CurrentBurnout = FMath::Clamp(CurrentBurnout + 15.0f, 0.0f, MaxBurnout);
	OnBurnoutLevelChanged.Broadcast(CurrentBurnout, MaxBurnout);

	UE_LOG(LogTemp, Log, TEXT("CastSunPulse: Serafina cast Sun Pulse wave (Radius %.0fuu). Burnout: %.1f/%.1f"), Radius, CurrentBurnout, MaxBurnout);

	if (GetWorld() && GetWorld()->GetGameInstance())
	{
		if (UAshenOath_GameEventSubsystem* EventBus = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_GameEventSubsystem>())
		{
			EventBus->BroadcastSpatialSoundRequested(nullptr, PulseLocation, 1.0f, 1.0f);
		}
	}

	OnWardenSpellCast.Broadcast(TEXT("SunPulse"), PulseLocation);
	return true;
}

bool UAshenOath_WardenComponent::DeploySanctuaryAnchor(FVector WardLocation)
{
	if (IsBurnoutExhausted())
	{
		UE_LOG(LogTemp, Warning, TEXT("DeploySanctuaryAnchor failed: Serafina is in Empathic Burnout exhaustion!"));
		return false;
	}

	CurrentBurnout = FMath::Clamp(CurrentBurnout + 20.0f, 0.0f, MaxBurnout);
	OnBurnoutLevelChanged.Broadcast(CurrentBurnout, MaxBurnout);

	UE_LOG(LogTemp, Log, TEXT("DeploySanctuaryAnchor: Sanctuary Ward deployed at %s (600uu sanity protection). Burnout: %.1f/%.1f"), *WardLocation.ToString(), CurrentBurnout, MaxBurnout);

	OnWardenSpellCast.Broadcast(TEXT("SanctuaryAnchor"), WardLocation);
	return true;
}

bool UAshenOath_WardenComponent::AbsorbTransferenceLoad(AActor* KaelenActor, float Amount)
{
	if (!KaelenActor || IsBurnoutExhausted())
	{
		UE_LOG(LogTemp, Warning, TEXT("AbsorbTransferenceLoad failed: Invalid Kaelen actor or Serafina exhausted."));
		return false;
	}

	// Restores Kaelen's sanity while Serafina absorbs the shadow sickness load
	if (KaelenActor->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(KaelenActor))
		{
			Sanity->HealSanity(Amount);
		}
	}

	CurrentBurnout = FMath::Clamp(CurrentBurnout + Amount, 0.0f, MaxBurnout);
	OnBurnoutLevelChanged.Broadcast(CurrentBurnout, MaxBurnout);

	UE_LOG(LogTemp, Log, TEXT("AbsorbTransferenceLoad: Serafina absorbed %.1f transference load from Kaelen. Current Burnout: %.1f/%.1f"), Amount, CurrentBurnout, MaxBurnout);
	return true;
}

void UAshenOath_WardenComponent::RecoverBurnout()
{
	CurrentBurnout = 0.0f;
	OnBurnoutLevelChanged.Broadcast(CurrentBurnout, MaxBurnout);
	UE_LOG(LogTemp, Log, TEXT("RecoverBurnout: Serafina completed resting recovery. Burnout reset to 0."));
}
