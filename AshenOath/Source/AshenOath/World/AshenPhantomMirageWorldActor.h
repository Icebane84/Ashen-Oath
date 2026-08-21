// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenPhantomMirageWorldActor.generated.h"

class UStaticMeshComponent;

/**
 * AAshenPhantomMirageWorldActor
 * 
 * Hallucinatory enemy that fades into ash when dismissed by companion grounding.
 */
UCLASS()
class ASHENOATH_API AAshenPhantomMirageWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenPhantomMirageWorldActor();

	virtual void BeginPlay() override;

	/** Dissolves phantom into ash motes */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Scenario4")
	void DisperseMirage();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Scenario4")
	bool IsRealThreat() const { return bIsRealPhysicalThreat; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MirageMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Scenario4")
	bool bIsRealPhysicalThreat = false;

private:
	bool bDispersed = false;
};
