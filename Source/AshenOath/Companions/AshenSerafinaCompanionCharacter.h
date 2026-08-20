// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenSerafinaCompanionCharacter.generated.h"

class UAshenSerafinaBurnoutComponent;
class UAshenSerafinaAuraFieldComponent;
class UAshenLuminousAegisNetComponent;
class UAshenTransferenceCatharsisComponent;
class UAshenTransferenceSymptomComponent;
class UAshenSerafinaStainedCuffMeshAdapter;
class UAshenSerafinaWeavingAIDirectorComponent;
class UAshenCompanionFormationComponent;
class UAshenCompanionTrustAccumulationComponent;

/**
 * AAshenSerafinaCompanionCharacter
 * Dedicated C++ Companion Character class for Serafina (The Lorekeeper / Soul Warden).
 * Hosts Empathic Burnout, Luminous Aegis Nets, Transference Catharsis, and Weaving AI Directors.
 */
UCLASS()
class ASHENOATH_API AAshenSerafinaCompanionCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	AAshenSerafinaCompanionCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenSerafinaBurnoutComponent* BurnoutComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenSerafinaAuraFieldComponent* AuraFieldComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenLuminousAegisNetComponent* AegisNetComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenTransferenceCatharsisComponent* CatharsisComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenTransferenceSymptomComponent* SymptomComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenSerafinaStainedCuffMeshAdapter* StainedCuffAdapter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenSerafinaWeavingAIDirectorComponent* WeavingAIDirector;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenCompanionFormationComponent* FormationComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath | Components")
	UAshenCompanionTrustAccumulationComponent* TrustComponent;
};
