// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenCampfireHearthAnchorActor.generated.h"

class USphereComponent;

/**
 * AAshenCampfireHearthAnchorActor
 * 
 * 3D world landmark managing the campfire hearth, warmth radius, and
 * companion interaction triggers.
 */
UCLASS()
class ASHENOATH_API AAshenCampfireHearthAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenCampfireHearthAnchorActor();

	virtual void BeginPlay() override;

	/** Ignites the hearth flame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Hearth")
	void IgniteHearth();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Hearth")
	bool IsHearthLit() const { return bHearthLit; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* WarmthRadius;

private:
	bool bHearthLit = false;
};
