// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulStateVectorComponent.h"
#include "AshenCompanionDiagnosticBifurcationComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenDiagnosticCompanionType : uint8
{
	GarrettTactical   UMETA(DisplayName = "Garrett (Tactical / Physical Diagnostic)"),
	SerafinaSpiritual UMETA(DisplayName = "Serafina (Spiritual / Corruption Diagnostic)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDiagnosticBehaviorChangedSignature, EAshenDiagnosticCompanionType, CompanionType, float, DiagnosticSeverity, FName, BehaviorStateTag);

/**
 * UAshenCompanionDiagnosticBifurcationComponent
 *
 * Diagnostic Bifurcation component attached to companions (UMB-SYS-005).
 * Garrett evaluates physical variables (Stamina/Poise); Serafina evaluates metaphysical variables (Corruption/Integration Debt).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionDiagnosticBifurcationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionDiagnosticBifurcationComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Diagnostic")
	void EvaluateKaelenSoulState(const FAshenSoulStateVector& SoulVector);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Diagnostic")
	EAshenDiagnosticCompanionType CompanionType = EAshenDiagnosticCompanionType::GarrettTactical;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Diagnostic|Events")
	FOnDiagnosticBehaviorChangedSignature OnDiagnosticBehaviorChanged;
};


