// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenInteractableActor.h"
#include "AshenSanctuaryActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSanctuaryRestedLocalSignature);

/**
 * AAshenSanctuaryActor
 * Checkpoint actor (Souls-like Bonfire). Refills all player resource stats
 * and updates their saved spawn point position.
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryActor : public AAshenInteractableActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Interact_Implementation(APawn* Player) override;

public:
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Sanry|Events")
	FOnSanctuaryRestedLocalSignature OnRested;
};
