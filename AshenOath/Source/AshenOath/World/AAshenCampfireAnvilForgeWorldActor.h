// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AAshenCampfireAnvilForgeWorldActor.generated.h"

/**
 * AAshenCampfireAnvilForgeWorldActor
 * 
 * Interactive world actor representing Garrett's traveling anvil at campfires and sanctuaries, opening the Runic Forge UI to inscribe sigils and ascend Oathbringer.
 */
UCLASS()
class ASHENOATH_API AAshenCampfireAnvilForgeWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenCampfireAnvilForgeWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Forge")
	void InteractWithAnvil();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Forge")
	bool IsAnvilActive() const { return bAnvilActive; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|World|Forge")
	bool bAnvilActive = true;
};
