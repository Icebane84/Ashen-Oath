// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenGarrettCompanionCharacter.generated.h"

class UAshenBurningSteelOilComponent;
class UAshenGhostbloomFlareComponent;
class UAshenAlchemicalCaltropGridComponent;
class UAshenAlchemicalTrapAIDirectorComponent;
class UAshenIgnitedCutlassMeshAdapter;
class UAshenCompanionFormationComponent;
class UAshenCompanionTrustAccumulationComponent;

/**
 * AAshenGarrettCompanionCharacter
 * Dedicated C++ Companion Character class for Garrett (The Rogue Alchemist).
 * Hosts Finite Alchemical Formulations, Caltrop Fields, Smoke Dampeners, and Trap AI Directors.
 */
UCLASS()
class ASHENOATH_API AAshenGarrettCompanionCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	AAshenGarrettCompanionCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenBurningSteelOilComponent* BurningSteelOilComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenGhostbloomFlareComponent* GhostbloomFlareComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenAlchemicalCaltropGridComponent* CaltropGridComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenAlchemicalTrapAIDirectorComponent* TrapAIDirector;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenIgnitedCutlassMeshAdapter* IgnitedCutlassAdapter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenCompanionFormationComponent* FormationComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenCompanionTrustAccumulationComponent* TrustComponent;
};
