// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenRuptureScarAnchorActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UAudioComponent;

/**
 * AAshenRuptureScarAnchorActor
 * 
 * 3D world spatial anchor representing a physicalized relationship scar:
 * - Emits subtle discord audio when approached during ActiveRupture
 * - Harmonizes into warm resonance upon RememberedReconciliation
 */
UCLASS()
class ASHENOATH_API AAshenRuptureScarAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenRuptureScarAnchorActor();

	virtual void BeginPlay() override;

	/** Initializes the scar anchor with specific rupture payload */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Rupture")
	void InitializeScarAnchor(FName CompanionName, ERelationalRuptureState InitialState, const FText& MemorialText);

	/** Updates the visual glow and audio timbre based on current relationship state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Rupture")
	void UpdateRuptureState(ERelationalRuptureState NewState);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Rupture")
	ERelationalRuptureState GetRuptureState() const { return CurrentState; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* PerceptionSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* ScarMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* AmbientResonanceAudio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Rupture")
	FName AssociatedCompanion = FName(TEXT("Garrett"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Rupture")
	ERelationalRuptureState CurrentState = ERelationalRuptureState::ActiveRupture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Rupture")
	FText HistoricalMemorialText;
};
