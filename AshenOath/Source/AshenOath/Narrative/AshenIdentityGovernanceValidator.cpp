// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Narrative/AshenIdentityGovernanceValidator.h"
#include "Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"

UAshenIdentityGovernanceValidator::UAshenIdentityGovernanceValidator()
{
	BalanceDataAsset = nullptr;
}

FAshenIdentityCognitiveStateVector UAshenIdentityGovernanceValidator::ValidateAndCompilePayload(
	const FString& RawJsonData,
	const TArray<FString>& ActiveImprintBuffer,
	const FAshenIdentityCognitiveStateVector& CurrentState)
{
	FAshenIdentityCognitiveStateVector OutMutableState = CurrentState;

	float MaxDelta = DEFAULT_MAX_ALLOWABLE_DELTA;
	int32 MaxPayloadKB = DEFAULT_MAX_JSON_PAYLOAD_SIZE_KB;

	if (BalanceDataAsset)
	{
		FIdentityGovernanceLimits Limits = BalanceDataAsset->GetClampedLimits();
		MaxDelta = Limits.MaxAllowableDelta;
		MaxPayloadKB = Limits.MaxJsonPayloadSizeKB;
	}

	// 1. Strict Serialization Bounds Verification
	const int32 PayloadSizeInBytes = RawJsonData.Len() * sizeof(TCHAR);
	if (PayloadSizeInBytes > (MaxPayloadKB * 1024))
	{
		UE_LOG(LogTemp, Error, TEXT("Governance Violation: JSON payload size (%d bytes) exceeds %d KB ceiling."), PayloadSizeInBytes, MaxPayloadKB);
		return CurrentState; // Reject entire transaction, execute deterministic fallback
	}

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(RawJsonData);

	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Governance Violation: Malformed JSON compilation input."));
		return CurrentState;
	}

	FAshenIdentityDeltaPayload CompiledDelta;
	if (!FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), FAshenIdentityDeltaPayload::StaticStruct(), &CompiledDelta, 0, 0))
	{
		UE_LOG(LogTemp, Error, TEXT("Governance Violation: JSON structural match schema failure."));
		return CurrentState;
	}

	// 2. Provenance Validation Pointers Audit (Anti-Hallucination Firewall)
	for (const FString& MemoryID : CompiledDelta.SupportingMemories)
	{
		if (!ActiveImprintBuffer.Contains(MemoryID))
		{
			UE_LOG(LogTemp, Warning, TEXT("Provenance Audit Blocked Hallucination: Memory ID '%s' not found in ActiveImprintBuffer!"), *MemoryID);
			return CurrentState; // Reject hallucinated execution pathing
		}
	}

	// 3. Execution Delta Clamping
	const float VerifiedDelta = FMath::Clamp(CompiledDelta.ProposedDelta, -MaxDelta, MaxDelta);

	// 4. Mutate Authoritative State Fields Natively
	if (CompiledDelta.TargetAxiom.Equals(TEXT("Corruption"), ESearchCase::IgnoreCase))
	{
		OutMutableState.Corruption = FMath::Clamp(CurrentState.Corruption + VerifiedDelta, 0.0f, 1.0f);
	}
	else if (CompiledDelta.TargetAxiom.Equals(TEXT("Resolve"), ESearchCase::IgnoreCase))
	{
		OutMutableState.Resolve = FMath::Clamp(CurrentState.Resolve + VerifiedDelta, 0.0f, 1.0f);
	}
	else if (CompiledDelta.TargetAxiom.Equals(TEXT("Isolation"), ESearchCase::IgnoreCase))
	{
		OutMutableState.Isolation = FMath::Clamp(CurrentState.Isolation + VerifiedDelta, 0.0f, 1.0f);
	}
	else if (CompiledDelta.TargetAxiom.Equals(TEXT("CompanionTrust"), ESearchCase::IgnoreCase))
	{
		OutMutableState.CompanionTrust = FMath::Clamp(CurrentState.CompanionTrust + VerifiedDelta, 0.0f, 1.0f);
	}

	return OutMutableState;
}

void UAshenIdentityGovernanceValidator::ApplyMemoryDecay(
	TArray<FAshenImprintRecord>& InOutImprints,
	int32 RestCycles)
{
	if (RestCycles <= 0)
	{
		return;
	}

	for (FAshenImprintRecord& Imprint : InOutImprints)
	{
		float Lambda = 0.02f;
		if (BalanceDataAsset)
		{
			Lambda = BalanceDataAsset->GetLambdaForCategory(Imprint.Category);
		}
		else
		{
			switch (Imprint.Category)
			{
			case EImprintSalienceCategory::Trauma: Lambda = 0.02f; break;
			case EImprintSalienceCategory::CompanionBond: Lambda = 0.08f; break;
			case EImprintSalienceCategory::HistoricalEpiphany: Lambda = 0.03f; break;
			case EImprintSalienceCategory::CombatTithe: Lambda = 0.12f; break;
			}
		}

		// Asymmetric Exponential Decay: S(t) = S_0 * e^(-lambda * t)
		Imprint.Salience = FMath::Clamp(Imprint.Salience * FMath::Exp(-Lambda * static_cast<float>(RestCycles)), 0.0f, 1.0f);
		Imprint.RestCyclesElapsed += RestCycles;
	}
}
