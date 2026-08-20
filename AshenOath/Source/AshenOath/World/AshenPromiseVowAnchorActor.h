// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "AshenPromiseVowAnchorActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

/**
 * AAshenPromiseVowAnchorActor
 * 
 * 3D world landmark entity marking a sacred location where a canonical promise was sworn.
 */
UCLASS()
class ASHENOATH_API AAshenPromiseVowAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenPromiseVowAnchorActor();

	virtual void BeginPlay() override;

	/** Honors the vow at this landmark */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Vow")
	void HonorVowAtAnchor();

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Vow")
	bool IsVowHonored() const { return bIsHonored; }

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Vow")
	FName GetAssociatedCompanion() const { return AssociatedCompanionName; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* VowRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* ShrineMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Vow")
	FName AssociatedCompanionName = FName(TEXT("Garrett"));

private:
	bool bIsHonored = false;
};
