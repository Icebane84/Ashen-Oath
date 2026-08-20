// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 304: Ashen Companion Diagnostic Bifurcation Component (UMB-SYS-005)

#include "AshenCompanionDiagnosticBifurcationComponent.h"

UAshenCompanionDiagnosticBifurcationComponent::UAshenCompanionDiagnosticBifurcationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CompanionType = EAshenDiagnosticCompanionType::GarrettTactical;
}

void UAshenCompanionDiagnosticBifurcationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenCompanionDiagnosticBifurcationComponent::EvaluateKaelenSoulState(const FAshenSoulStateVector& SoulVector)
{
	float Severity = 0.0f;
	FName Tag = FName("Diagnostic_Normal");

	if (CompanionType == EAshenDiagnosticCompanionType::GarrettTactical)
	{
		// Garrett tracks physical stamina & poise
		Severity = FMath::Clamp(1.0f - (SoulVector.Stamina / 100.0f), 0.0f, 1.0f);
		if (Severity > 0.5f)
		{
			Tag = FName("Garrett_FranticPhysicalWarning");
		}
	}
	else // SerafinaSpiritual
	{
		// Serafina tracks metaphysical corruption & integration debt
		Severity = FMath::Clamp(SoulVector.IntegrationDebt / 100.0f, 0.0f, 1.0f);
		if (Severity > 0.4f)
		{
			Tag = FName("Serafina_WardDestabilized_Terror");
		}
	}

	OnDiagnosticBehaviorChanged.Broadcast(CompanionType, Severity, Tag);

	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionDiagnosticBifurcationComponent: Diagnostic Evaluated — Type %d, Severity: %.2f, Tag: '%s'."),
		(int32)CompanionType, Severity, *Tag.ToString());
}


