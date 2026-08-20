// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenSerafinaIdentityCompilerSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnIdentityCompiledSignature, FName, ChosenInterpretiveLens, float, CompiledIntegrityMetric);

/**
 * UAshenSerafinaIdentityCompilerSubsystem
 *
 * World Subsystem driving Serafina's campfire interpretation ritual (Accountability, Grace, Utility)
 * and executing CompileIdentity() directly into the 28-byte FSoulStateVector (Directives #3 & #5).
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaIdentityCompilerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|IdentityCompiler")
	bool CompileIdentityForCampfireLens(FName InterpretiveLensTag);

	UFUNCTION(BlueprintPure, Category = "AshenOath|IdentityCompiler")
	FName GetActiveInterpretiveLens() const { return ActiveInterpretiveLens; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|IdentityCompiler|Events")
	FOnIdentityCompiledSignature OnIdentityCompiled;

private:
	FName ActiveInterpretiveLens;
};
