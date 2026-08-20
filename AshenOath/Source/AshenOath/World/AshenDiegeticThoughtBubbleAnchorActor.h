// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenDiegeticThoughtBubbleAnchorActor.generated.h"

/**
 * AAshenDiegeticThoughtBubbleAnchorActor
 * World anchor rendering in-world 3D thought bubble text above companions.
 */
UCLASS()
class ASHENOATH_API AAshenDiegeticThoughtBubbleAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenDiegeticThoughtBubbleAnchorActor();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void SpawnInWorldThoughtBubble(FText ThoughtText, FVector WorldLocation);
};
