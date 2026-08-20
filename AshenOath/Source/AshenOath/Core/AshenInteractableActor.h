// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenInteractableInterface.h"
#include "AshenInteractableActor.generated.h"

class UBoxComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractedSignature, APawn*, Player);

/**
 * AAshenInteractableActor
 * Base class for interactive world actors (chests, doors, levers).
 */
UCLASS()
class ASHENOATH_API AAshenInteractableActor : public AActor, public IAshenInteractableInterface
{
	GENERATED_BODY()
	
public:	
	AAshenInteractableActor();

protected:
	virtual void BeginPlay() override;

public:	
	// --- IAshenInteractableInterface Implementation ---
	virtual void Interact_Implementation(APawn* Player) override;
	virtual FString GetInteractionText_Implementation() const override;

public:
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Interactable|Events")
	FOnInteractedSignature OnInteracted;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interactable Settings")
	FString InteractionText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interactable Settings")
	bool bIsOneShot;

	UPROPERTY(VisibleAnywhere, Category = "Interactable State")
	bool bWasUsed;
};
