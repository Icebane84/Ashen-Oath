// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenInteractionComponent.generated.h"

/**
 * UAshenInteractionComponent
 * Attached to the Player. Handles forward camera trace checks to identify interactable items,
 * broadcasts HUD text notifications, and routes wielder input interact actions.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenInteractionComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Trigger interaction on the currently cached interactive actor */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Interaction")
	void TriggerInteraction();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction Settings")
	float InteractionDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction Settings")
	bool bDrawDebugLine;

private:
	UPROPERTY()
	AActor* CachedInteractable;

	TWeakObjectPtr<class UCameraComponent> CachedCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction Settings", meta = (AllowPrivateAccess = "true"))
	float TraceInterval;

	float TimeSinceLastTrace;
};
