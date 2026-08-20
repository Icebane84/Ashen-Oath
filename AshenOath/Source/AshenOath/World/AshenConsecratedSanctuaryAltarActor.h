// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenConsecratedSanctuaryAltarActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UAudioComponent;

/**
 * AAshenConsecratedSanctuaryAltarActor
 * 
 * 3D world sanctuary altar where the trio rests, cools relational friction,
 * and performs multi-author living journal reflections.
 */
UCLASS()
class ASHENOATH_API AAshenConsecratedSanctuaryAltarActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenConsecratedSanctuaryAltarActor();

	virtual void BeginPlay() override;

	/** Begins a sanctuary resting communion session */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Sanctuary")
	bool InitiateRestSession();

	/** Concludes the session, applying friction cooling */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Sanctuary")
	void ConcludeRestSession();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Sanctuary")
	bool IsResting() const { return bIsSessionActive; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SanctuaryPerimeter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* AltarMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* HearthfireAudio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Sanctuary")
	float FrictionCoolingRate = 0.15f;

private:
	bool bIsSessionActive = false;
};
