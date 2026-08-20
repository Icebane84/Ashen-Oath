// Copyright Phoenix Protocol. All rights reserved.

#include "AshenInteractionComponent.h"
#include "AshenInteractableInterface.h"
#include "AshenOath_GameEventSubsystem.h"
#include "AshenGameSettings.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

UAshenInteractionComponent::UAshenInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	InteractionDistance = 300.0f;
	bDrawDebugLine = false;
	CachedInteractable = nullptr;
	CachedCamera = nullptr;
	TraceInterval = 0.1f; // Run trace checks at 10Hz to protect performance
	TimeSinceLastTrace = 0.0f;
}

void UAshenInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// Load configuration-driven settings
	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		InteractionDistance = Settings->PlayerInteractionDistance;
		TraceInterval = Settings->PlayerInteractionInterval;
	}

	// Cache camera reference at initialization to avoid per-frame component query bottlenecks
	if (AActor* OwnerActor = GetOwner())
	{
		CachedCamera = OwnerActor->FindComponentByClass<UCameraComponent>();
	}
}

void UAshenInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!GetWorld() || !GetWorld()->GetGameInstance()) return;

	TimeSinceLastTrace += DeltaTime;
	if (TimeSinceLastTrace < TraceInterval)
	{
		return;
	}
	TimeSinceLastTrace = 0.0f;

	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (!OwnerCharacter) return;

	UCameraComponent* FollowCamera = CachedCamera.Get();
	if (!FollowCamera)
	{
		// Fallback check in case camera was instantiated late
		CachedCamera = OwnerCharacter->FindComponentByClass<UCameraComponent>();
		FollowCamera = CachedCamera.Get();
		if (!FollowCamera) return;
	}

	FVector StartLocation = FollowCamera->GetComponentLocation();
	FVector EndLocation = StartLocation + FollowCamera->GetForwardVector() * InteractionDistance;

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(OwnerCharacter);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, QueryParams);

	if (bDrawDebugLine)
	{
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, bHit ? FColor::Green : FColor::Red, false, -1.0f, 0, 1.0f);
	}

	AActor* HitActor = bHit ? HitResult.GetActor() : nullptr;

	if (HitActor && HitActor->Implements<UAshenInteractableInterface>())
	{
		if (HitActor != CachedInteractable)
		{
			CachedInteractable = HitActor;
			FString PromptText = IAshenInteractableInterface::Execute_GetInteractionText(HitActor);

			UAshenOath_GameEventSubsystem* EventBus = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_GameEventSubsystem>();
			if (EventBus)
			{
				EventBus->BroadcastInteractionHintShown(PromptText);
			}
		}
	}
	else
	{
		if (CachedInteractable)
		{
			CachedInteractable = nullptr;

			UAshenOath_GameEventSubsystem* EventBus = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_GameEventSubsystem>();
			if (EventBus)
			{
				EventBus->BroadcastInteractionHintHidden();
			}
		}
	}
}

void UAshenInteractionComponent::TriggerInteraction()
{
	if (CachedInteractable && CachedInteractable->Implements<UAshenInteractableInterface>())
	{
		APawn* OwnerPawn = Cast<APawn>(GetOwner());
		IAshenInteractableInterface::Execute_Interact(CachedInteractable, OwnerPawn);
	}
}
