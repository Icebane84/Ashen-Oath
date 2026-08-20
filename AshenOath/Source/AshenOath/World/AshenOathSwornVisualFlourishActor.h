// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenOathSwornVisualFlourishActor.generated.h"

/**
 * AAshenOathSwornVisualFlourishActor
 * World actor driving golden oath rune particle burst on swearing/fulfilling an oath.
 */
UCLASS()
class ASHENOATH_API AAshenOathSwornVisualFlourishActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenOathSwornVisualFlourishActor();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void TriggerOathSwornVisualFlourish();
};
